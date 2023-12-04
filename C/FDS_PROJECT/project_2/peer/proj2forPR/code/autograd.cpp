#include "autograd.hpp"

/********************
 * simplifyTree
 * ************
 * This function will try its best to remove redundant nodes in the tree.
 * Here are the rules we apply:
 * 1. replace (x + 0), (0 + x), (x - 0), (x * 1), (1 * x), (x / 1), (x ^ 1) by x
 * 2. replace (x - x), (x * 0), (0 * x), (0 / x), (0 ^ x) by 0
 * 3. replace (x / x), (x ^ 0) by 1
 * 
 * We have to denote that simplification is actually a redundant thing,
 * we have to list special cases for possible simplification.
 * So there is a lot of if-else statements to maintain the logic as possible as we can.
*/
Tree* simplifyTree(const Tree* root) {
    if (root == nullptr)
        return nullptr;
    
    //  recursively simplify the left and right subtree
    Tree *l = simplifyTree(root->left);
    Tree *r = simplifyTree(root->right);
    
    if (root->value[0] == '+') {
        if (l->value == "0") {
            //  (0 + x), we just have to return x
            return r;
        } else if (r->value == "0") {
            //  (x + 0), we just have to return x
            return l;
        } else if (isConstant(l->value) && isConstant(r->value)) {
            //  (const + const), we can calculate the result
            return new Tree(calculateConstRes(l->value, r->value, "+"));
        } else {
            //  (x + y), we just have to return the original tree
            return new Tree("+", l, r);
        }
    } else if (root->value[0] == '-' && root->value.length() == 1) {
        //  Here we have to emphasize again on "-", which is really a headache
        //  In the expression tree, we allow constant like -1 to occur on the single node
        //  So we have to carefully investigate whether we encounter a binary operator or a unary operator
        if (l->value == "0" && r->value == "0") {
            //  (0 - 0), we just have to return 0
            return new Tree("0");
        } else if (l->value == "0") {
            //  (0 - x), we just have to return -x
            Tree *result = new Tree("neg", r, nullptr);
            return result;
        } else if (r->value == "0") {
            //  (x - 0), we just have to return x
            return l;
        } else if (isConstant(l->value) && isConstant(r->value)) {
            //  (const - const), we can calculate the result
            return new Tree(calculateConstRes(l->value, r->value, "-"));
        } else {
            //  (x - y), we just have to return the original tree
            return new Tree("-", l, r);
        }
    } else if (root->value[0] == '*') {
        if (l->value == "0" || r->value == "0") {
            //  (0 * x), (x * 0), we just have to return 0
            return new Tree("0");
        } else if (l->value == "1") {
            //  (1 * x), we just have to return x
            return r;
        } else if (r->value == "1") {
            //  (x * 1), we just have to return x
            return l;
        } else if (isConstant(l->value) && isConstant(r->value)) {
            //  (const * const), we can calculate the result
            return new Tree(calculateConstRes(l->value, r->value, "*"));
        } else if ((l->value == "/" && isomorphicTree(l->right, r))
                || (r->value == "/" && isomorphicTree(r->right, l))) {
            //  If the parent operator is '*', things are easier
            //  (x / y) * y, x * (y / x), we just have to return x(y)
            if (isomorphicTree(l->right, r))
                return l->left;
            else if (isomorphicTree(r->right, l))
                return r->left;
        } else {
            //  (x * y), we just have to return the original tree
            return new Tree("*", l, r);
        }
    } else if (root->value[0] == '/') {
        if (l->value == "0") {
            //  (0 / x), we just have to return 0
            return new Tree("0");
        } else if (r->value == "0") {
            //  (x / 0), we just have to return error
            cout << "Error: division by zero" << endl;
        } else if (r->value == "1") {
            //  (x / 1), we just have to return x
            return l;
        } else if (isConstant(l->value) && isConstant(r->value)) {
            //  (const / const), we can calculate the result
            return new Tree(calculateConstRes(l->value, r->value, "/"));
        } else if (isomorphicTree(l, r)) {
            //  (x / x), we just have to return 1
            return new Tree("1");
        } else if ((l->value == "*" && (isomorphicTree(l->left, r) || isomorphicTree(l->right, r)))
                || (r->value == "*" && (isomorphicTree(r->left, l) || isomorphicTree(r->right, l)))) {
            //  (x * y) / x, (x * y) / y, we just have to return y(x)
            //  However, if we meet x / (x * y), y / (x * y), we have to return 1 / y(x)
            if (isomorphicTree(l->left, r))
                return l->right;
            else if (isomorphicTree(l->right, r))
                return l->left;
            else if (isomorphicTree(r->left, l))
                return new Tree("/", new Tree("1"), r->right);
            else if (isomorphicTree(r->right, l))
                return new Tree("/", new Tree("1"), r->left);
        } else {
            //  (x / y), we just have to return the original tree
            return new Tree("/", l, r);
        }
    } else if (root->value[0] == '^') {
        if (r->value == "0") {
            //  (x ^ 0), we just have to return 1
            return new Tree("1");
        } else if (l->value == "0") {
            //  (0 ^ x), we just have to return 0
            return new Tree("0");
        } else if (r->value == "1") {
            //  (x ^ 1), we just have to return x
            return l;
        } else if (isConstant(l->value) && isConstant(r->value)) {
            //  (const ^ const), we can calculate the result
            return new Tree(calculateConstRes(l->value, r->value, "^"));
        } else {
            //  (x ^ y), we just have to return the original tree
            return new Tree("^", l, r);
        }
    } else if (root->value == "neg") {
        if (isConstant(l->value)) {
            //  (-const), we can calculate the result
            return new Tree(calculateConstRes(l->value, "-1", "*"));
        } else {
            //  (-x), we just have to return the original tree
            return new Tree("neg", l, nullptr);
        }
    }
    else {
        //  (x), we just have to return the original tree
        return new Tree(root->value, l, r);
    }

    cout << "Error: simplifyTree, returning nullptr" << endl;
    return nullptr;
}

/********************************
 * autoGrad
 * **************
 * This function will automatically calculate the derivative of the expression.
 * 
 * Input:
 * root: the root of the expression tree
 * var: the variable we want to calculate the derivative
 * variables: the vector of variables in the expression
 * 
 * Output:
 * the root of the derivative expression tree
*/
Tree* autoGrad(Tree* root, const string& var, const vector<string>& variables) {
    if (root == nullptr)
        return nullptr;

    //  Recursively calculate the derivative of the left subtree and the right subtree
    Tree *ld = autoGrad(root->left, var, variables);
    Tree *rd = autoGrad(root->right, var, variables);
    
    if (root->value == var) {
        //  If the current node is the variable itself
        //  Rule : d/dx(x) = 1
        return new Tree("1");
    } else if (isConstant(root->value) || isPartialVariable(root->value, var, variables) || root->value == "e") {
        //  If the current node is a constant or a partial variable
        //  Rule : d/dx(const) = 0
        return new Tree("0");
    } else if (root->value[0] == '+') {
        //  Rule : d/dx(f + g) = d/dx(f) + d/dx(g)
        return new Tree("+", ld, rd);
    } else if (root->value[0] == '-') {
        //  Rule : d/dx(f - g) = d/dx(f) - d/dx(g)
        return new Tree("-", ld, rd);
    } else if (root->value[0] == '*') {
        //  Rule : d/dx(f * g) = f * d/dx(g) + g * d/dx(f)
        Tree *result = new Tree("+");
        result->left = new Tree("*", ld, root->right);
        result->right = new Tree("*", root->left, rd);
        return result;
    } else if (root->value[0] == '/') {
        //  Rule : d/dx(f / g) = (d/dx(f) * g - f * d/dx(g)) / g ^ 2
        Tree *result = new Tree("/");
        result->left = new Tree("-", new Tree("*", ld, root->right), new Tree("*", root->left, rd));
        result->right = new Tree("^", root->right, new Tree("2"));
        return result;
    } else if (root->value[0] == '^') {
        //  Rule : d/dx(f ^ g) = f ^ g * (d/dx(g) * ln(f) + g * d/dx(f) / f)
        //  However, for possible simplification, we first check if 
        //  the base and the exponent are constants or not
        //  which will help us to simplify the expression
        bool isBaseConstant = checkConstant(root->left, var, variables);
        bool isExponentConstant = checkConstant(root->right, var, variables);

        if (root->left->value[0] == 'e') {
            //  If the base is e, we can simplify the expression
            //  Rule : d/dx(e ^ g) = e ^ g * d/dx(g)
            Tree *result = new Tree("*");
            result->left = new Tree("^", root->left, root->right);
            result->right = autoGrad(root->right, var, variables);
            return result;
        } else
        if (isBaseConstant && isExponentConstant) {
            //  If both the base and the exponent are constants
            //  Rule : d/dx(const ^ const) = 0
            return new Tree("0");
        } else if (isBaseConstant) {
            //  If the base is a constant
            //  Rule : d/dx(const ^ g) = const ^ g * (d/dx(g) * ln(const))
            Tree *result = new Tree("*");
            result->left = new Tree("log", new Tree("e"), root->left);
            result->right = new Tree("^", root->left, root->right);
            return result;
        } else if (isExponentConstant) {
            //  If the exponent is a constant
            //  Rule : d/dx(f ^ const) = （const - 1) * f ^ (const - 1) * d/dx(f)
            Tree *result = new Tree("*");
            result->left = new Tree("*", autoGrad(root->left, var, variables), root->right);
            result->right = new Tree("^", root->left, new Tree("-", root->right, new Tree("1")));
            return result;
        } else {
            //  If both the base and the exponent are variables
            //  Rule : d/dx(f ^ g) = f ^ g * (d/dx(g) * ln(f) + g * d/dx(f) / f)
            Tree *result = new Tree("*");
            result->left = root;

            Tree *resultRight = new Tree("+");
            Tree *logTree = new Tree("log", new Tree("e"), root->left);
            resultRight->left = new Tree("*", root->right, autoGrad(logTree, var, variables));
            resultRight->right = new Tree("*", logTree, autoGrad(root->right, var, variables));

            result->right = resultRight;
            return result;
        }
    } else if (root->value.substr(0, 2) == "ln") {
        //  Rule : d/dx(ln(f)) = d/dx(f) / f
        Tree *result = new Tree("/");
        result->left = autoGrad(root->left, var, variables);
        result->right = root->left;
        return result;
    } else if (root->value.substr(0, 3) == "log") {
        //  We can apply the logorithm rule and convert log to ln
        //  Then we can simply recursively call the autoGrad function
        if (root->left->value == "e") {
            //  Turn log to ln and use the rule of ln
            Tree *result = autoGrad(new Tree("ln", root->right, nullptr), var, variables);
            return result;
        } else {
            //  Rule : log(f, g) = ln(g) / ln(f)
            //  Turn log to ln and use the rule of ln
            Tree *result = autoGrad(new Tree("/", new Tree("ln", root->right, nullptr), new Tree("ln", root->left, nullptr))
                                    , var, variables);
            return result;
        }
    } else if (root->value.substr(0, 3) == "pow") {
        //  Turn pow to ^ and use the rule of ^
        return autoGrad(new Tree("^", root->left, root->right), var, variables);
    } else if (root->value.substr(0, 3) == "exp") {
        //  Turn exp to e ^ and use the rule of ^
        return autoGrad(new Tree("^", new Tree("e"), root->left), var, variables);
    } else if (root->value.substr(0, 3) == "sin") {
        //  Rule : d/dx(sin(f)) = cos(f) * d/dx(f)
        Tree *result = new Tree("*");
        result->left = autoGrad(root->left, var, variables);
        result->right = new Tree("cos", root->left, nullptr);
        return result;
    } else if (root->value.substr(0, 3) == "cos") {
        // Rule : d/dx(cos(f)) = -sin(f) * d/dx(f)
        Tree *result = new Tree("*");
        result->left = autoGrad(root->left, var, variables);
        result->right = new Tree("neg", new Tree("sin", root->left, nullptr), nullptr);
        return result;
    } else if (root->value.substr(0, 3) == "tan") {
        //  Rule : d/dx(tan(f)) = sec(f) ^ 2 * d/dx(f)
        Tree *result = new Tree("*");
        result->left = autoGrad(root->left, var, variables);
        result->right = new Tree("^", new Tree("sec", root->left, nullptr), new Tree("2"));
        return result;
    } else if (root->value.substr(0, 3) == "neg") {
        //  Rule : d/dx(-f) = -d/dx(f)
        return new Tree("neg", autoGrad(root->left, var, variables), nullptr);
    }

    //  If we cannot find the rule to be applied, we just return the original tree
    cout << "Error: autoGrad, returning itself; No rule to be applied! Value: " << root->value << endl;
    return root;
}