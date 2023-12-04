#include "check.hpp"

/*****************************
 * isomorphicTree
 * **************
 * Check if two trees are isomorphic
 * return 1 if they are, 0 if not
 * The function is almost the same as what 
 * we have done in PTA's HW
*/
int isomorphicTree(Tree* T1, Tree* T2) {
    if (T1 == nullptr || T2 == nullptr) {
        if ((T1 == nullptr && T2 != nullptr) || (T1 != nullptr && T2 == nullptr)) {return 0;} 
            else {return 1;}
    } else {
        if (T1->value == T2->value) {
            int l = isomorphicTree(T1->left, T2->left) && isomorphicTree(T1->right, T2->right);
            int r = isomorphicTree(T1->left, T2->right) && isomorphicTree(T1->right, T2->left);
            //  We have to note that the order of the children of 
            //  log and pow function cannot be swapped
            //  So the second check (r) cannot happen in these two cases
            if (T1->value == "log" || T1->value == "pow") {
                r = 0;
            }
            //  If the two trees are isomorphic, then either l or r should be 1
            if (l || r) {return 1;} 
                else {return 0;}
        } else {
            return 0;
        }
    }
}

/*******************************
 * isValid
 * **********
 * Check if the token is valid analyze and return 
 * the length of the token
 * Here are the possible cases:
 * 1. A constant
 * 2. A variable
 * 3. A unary operator
 * 4. A binary operator
*/
int isValid(const string& expression, const int i) {
    int length = 0;

    //  token: the string started from the current position (i)
    string token = expression.substr(i);
    
    if (token[0] >= '0' && token[0] <= '9') {
        //  If the token is a constant
        //  Iterate until we encounter a non-constant character
        for (auto i : token) {
            if (i >= '0' && i <= '9') {
                length++;
            } else {
                break;
            }
        }
    } else if (isUnaryOperator(expression, i)) {
        //  If the token is a unary operator
        //  Function unaryExpressionParser will return the length of the expression
        length = unaryExpressionParser(token);
    } else if (isBinaryOperator(token)) {
        //  If the token is a binary operator
        //  The length of the token is definitely 1
        length = 1;
    } else if (isVariable(token)) {
        length = isVariable(token);
    }
    return length;
}

/***************************
 * isVariable
 * **********
 * Check if the token is a variable
 * return the length of it if it is, 0 if not
*/
int isVariable(const string& c) {
    if (c[0] >= 'a' && c[0] <= 'z') {
        if (c.substr(0, 3) == "sin" || c.substr(0, 3) == "cos" || c.substr(0, 3) == "tan" ||
            c.substr(0, 3) == "log" || c.substr(0, 3) == "pow" || c.substr(0, 3) == "exp" ||
            c.substr(0, 3) == "neg") {
            if (c[3] >= 'a' && c[3] <= 'z') {
                int i;
                for (i = 3; i < c.length(); i++) {
                    if (c[i] >= 'a' && c[i] <= 'z') {
                        continue;
                    } else {
                        break;
                    }
                }
                return i;
            } else {
                return 0;
            }
        } else if (c.substr(0, 2) == "ln") {
            if (c[2] >= 'a' && c[2] <= 'z') {
                int i;
                for (i = 2; i < c.length(); i++) {
                    if (c[i] >= 'a' && c[i] <= 'z') {
                        continue;
                    } else {
                        break;
                    }
                }
                return i;
            } else {
                return 0;
            }
        } else {
            int i;
            for (i = 0; i < c.length(); i++) {
                if (c[i] >= 'a' && c[i] <= 'z') {
                    continue;
                } else {
                    break;
                }
            }
            return i;
        }
    } else {
        return 0;
    }
}

/*************************
 * isUnaryOperator
 * ***************
 * Check if the token is a unary operator
 * return 1 if it is, 0 if not
 * Here are the possible cases:
 * ln, log, sin, cos, tan, pow, exp, negative(which is really a headache)
*/
int isUnaryOperator(const string& expression, const int i) {
    //  token: the string started from the current position (i)
    string c = expression.substr(i);
    if (c.substr(0, 2) == "ln" || c.substr(0,3) == "log" || 
        c.substr(0, 3) == "sin" || c.substr(0, 3) == "cos" || c.substr(0, 3) == "tan" ||
        c.substr(0, 3) == "pow" || c.substr(0, 3) == "exp") {
        return 1;
    } else if (c[0] == '-') {
        /*****************************
         * Unary operator minus is really a headache
         * Here we separate it into three cases to judge:
         * 1. The first token of the expression
         * 2. The token after a binary operator but not a right parenthesis
         * 3. The token after a left parenthesis
        */
        if (i == 0) {
            return 1;
        } else if (isBinaryOperator(expression.substr(i - 1, 1)) && expression[i - 1] != ')') {
            return 1;
        } else if (expression[i - 1] == '(') {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/***********************
 * isBinaryOperator
 * **************
 * Check if the token is a binary operator
 * return 1 if it is, 0 if not
 * Here are the possible cases:
 * +, -, *, /, (, ), ^
*/
int isBinaryOperator(const string& c) {
    switch (c[0]) {
        case '+': case '-': case '*': case '/':
        case '(': case ')': case '^': 
            return 1;
        default:
            return 0;
    }
}

/***********************
 * Precedence
 * **************
 * Return the precedence of the operator
 * Here are the possible cases:
 * +, -: 1
 * *, /: 2
 * ^: 3
 * (, ): 0
*/
int Precedence(const string& op) {
    switch (op[0])
    {
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

/*******************
 * isConstant
 * **********
 * Check if the token is a constant
 * return 1 if it is, 0 if not
 * Here are the possible cases:
*/
int isConstant(const string& c) {
    //  the token is a constant if 
    //  1. it is a positive number starting with a digit character
    //  2. it is a number with a preceding minus operator
    return (c[0] >= '0' && c[0] <= '9') || (c[0] == '-' && c[1] >= '0' && c[1] <= '9');
}

/**********************
 * isPartialVariable
 * *************
 * Check if the token is a partial variable
 * return 1 if it is, 0 if not
 * Here are the possible cases to check:
 * 1. Whether the token is the same as the main variable
 * 2. Whether the token is in the vector of variables
*/
int isPartialVariable(const string& partial, const string& main, const vector<string>& variables) {
    if (partial == main)
        return 0;
    
    //  Iterate through the vector of variables
    for (auto i : variables) {
        if (i == partial)
            return 1;
    }

    return 0;
}

/*********************
 * checkConstant
 * ************
 * The function is written for the case of pow function
 * Check if the base(exponent) of the pow function is a constant (relatively)
*/
bool checkConstant(Tree *root, const string& var, const vector<string>& variables) {
    if (root == nullptr) {
        return true;
    }

    //  If it can be seen as a constant when operating partial differentiation
    //  Possible cases:
    //  1. A constant
    //  2. A partial variable
    //  3. A binary operator (look into it recursively)
    if (isConstant(root->value) || isPartialVariable(root->value, var, variables) || isBinaryOperator(root->value)) {
        return checkConstant(root->left, var, variables) && checkConstant(root->right, var, variables);
    } else {
        return false;
    }
    
}

/************************
 * unaryExpressionParser
 * ***************
 * When we call this function, it means we have encountered a unary operator,
 * What remains to be done is to find the end of it.
 * Here, to simplify the problem, we see the unary operator and its operand as a whole
 * And we will further analyze the operand when constructing the expression tree
 * 
 * Things to be done:
 * Find the total length of the unary operator and its operand
 * then return the length
*/
int unaryExpressionParser(const string& c) {
    string token;
    //  the length of the unary operator
    //  log, pow, exp, sin, cos, tan: 3
    //  ln: 2
    //  -: 1
    int adder;  
    if (c.substr(0, 2) == "ln") {
        token = c.substr(2);
        adder = 2;
    } else if (c.substr(0, 3) == "log" || c.substr(0, 3) == "pow" || c.substr(0, 3) == "exp" ||
               c.substr(0, 3) == "sin" || c.substr(0, 3) == "cos" || c.substr(0, 3) == "tan") {
        token = c.substr(3);
        adder = 3;
    } else if (c[0] == '-') {
        token = c.substr(1);
        adder = 1;
    }

    //  We check if there is a parenthesis after the unary operator
    //  (which will make the problem more complicated)
    //  We have to find the right parenthesis that matches the left parenthesis
    //  which represents the end of the operand
    if (token[0] == '(') {
        int i = 1;
        int count = 1;
        while (count != 0) {
            if (token[i] == '(') {
                count++;
            } else if (token[i] == ')') {
                count--;
            }
            i++;
        }
        return i + adder;
    } else {
        //  If there is no parenthesis, 
        //  which means there is only a single operand after it
        //  we just need to find the end of the operand
        return isValid(token, 0) + adder;
    }
}

/************************
 * checkParenthesis
 * ***************
 * The function works when we want to print the expression
 * We know a expression tree natually states the precedence of the operators
 * But when we turn it into an inorder expression, we have to add parenthesis if needed
 * 
 * Things to be done:
 * Check the precedence of the operator
 * return 1 if the child node needs parenthesis, 0 if not
*/
int checkParenthesis(const Tree* parent, const Tree* child) {
    if (parent == nullptr) {
        return 0;
    } else if (child->left == nullptr || child->right == nullptr) {
        return 0;
    } else if (isBinaryOperator(parent->value) && isBinaryOperator(child->value)) {
        //   If the parent node and the child node are both binary operators
        //   We have to check the precedence of the two operators
        //  If the precedence of the parent node is higher than the child node,
        //  but we have to calculate the operations in the children nodes first,
        //  a parenthesis will be added to guarantee the correctness of the expression
        if ((Precedence(parent->value) > Precedence(child->value))
         || (parent->value == "^" && child->value == "^")
         || (parent->value == "/" && child->value == "/")
         || (parent->value == "/" && child->value == "*")) {
            //  we have to be very careful if the parent operator and the child operator
            //  are of the same precedence, which means we have to check the associativity
            //  of the operators. 
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/****************************
 * calculateConstRes
 * ***************
 * The function is written when we simplifying the expression tree
 * When we encounter a constant expression, we can calculate the result
 * However, we have to be careful about the type of the result
 * If it is an integer, we don't need to return the double type,
 * which we bring further convenience to the program
*/
string calculateConstRes(const string a, const string b, const string op) {
    switch (op[0]) {
        case '+':
            if ((int)(stoi(a) + stoi(b)) == (double)(stod(a) + stod(b)))
            {return to_string((int)(stoi(a) + stoi(b)));}
                else {return to_string(stod(a) + stod(b));}
        case '-':
            if ((int)(stoi(a) - stoi(b)) == (double)(stod(a) - stod(b)))
            {return to_string((int)(stoi(a) - stoi(b)));}
                else {return to_string(stod(a) - stod(b));}
        case '*':
            if ((int)(stoi(a) * stoi(b)) == (double)(stod(a) * stod(b))) 
            {return to_string((int)(stoi(a) * stoi(b)));}
                else {return to_string(stod(a) * stod(b));}
        case '/':
            if ((int)(stoi(a) / stoi(b)) == (double)(stod(a) / stod(b))) 
            {return to_string((int)(stoi(a) / stoi(b)));}
                else {return to_string(stod(a) / stod(b));}
        case '^':
            if ((int)(pow(stoi(a), stoi(b))) == (double)(pow(stod(a), stod(b)))) 
            {return to_string((int)(pow(stoi(a), stoi(b))));}
                else {return to_string(pow(stod(a), stod(b)));}
        default:
            return "";
    }
}