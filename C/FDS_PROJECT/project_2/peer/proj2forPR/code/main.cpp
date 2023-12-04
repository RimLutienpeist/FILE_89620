#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include "autograd.hpp"
#include "tree.hpp"
#include "check.hpp"

using namespace std;

/*********************
 * Tokenize
 * ********
 * This function will tokenize the expression
 * and return a vector of tokens
 * 
 * Note: This function will not check the validity of the expression
 *       It will only check the validity of each token
 *       Unary operators will be tokenized with its operands as a whole,
 *       for example, "-(x+y)" will be tokenized as "-(x+y)", not as "-" "(" "x" "+" "y" ")"
 *       This is for the convenience of parsing
*/
vector<string> Tokenize(const string& expression) {
    vector<string> tokens;
    int i = 0;  //  iterator

    //  iterate through the expression
    while (i < expression.size()) {
        //  call isValid Function and it will return the length of the next token
        int length = isValid(expression, i);

        //  if the length is not 0, then we get a valid token
        if (length) {
            //  get the token
            string token = expression.substr(i, length);

            //  Note this is a very special case
            //  If the minus operator becomes a unary operator
            //  We tag it as a '#' operator for further convenience
            if (token[0] == '-' && length > 1) {
                token[0] = '#';
            }
            //  push the token into the vector
            tokens.push_back(token);
            //  update the iterator
            i += length;
        } else {
            //  if the length is 0, then we get an invalid token
            cerr << "Invalid token: " << expression.substr(i) << endl;
            i++;
        }
    }

    //  don't forget to return the vector
    return tokens;
}

/************************
 * parseExpression
 * *************
 * This function will do the following job:
 * 1. Convert the infix expression to postfix expression
 * 2. Construct the expression tree
 * 
 * Note:
 * While constructing the expression tree, we will process
 * the unary operators and functions by recursively calls
 * 
 * Normal operators and operands will be alright to apply the
 * method taught in the class, by using operator stack and operand stack
 * 
 * However, unary operators and functions are a little bit different
 * First, we regard it as a common operand and find the right position for it
 * in the expression tree, then we construct it in detail by calling the function 
 * recursively.
 * 
*/
Tree *parseExpression(const vector<string>& tokens) {
    stack<Tree *> treeStack;    //  expression tree constructor
    stack<string> opStack;      //  operator stack
    vector<string> postfix;     //  postfix expression

    //  iterate through the tokens
    for (auto i : tokens) {
        if (!isBinaryOperator(i)) {
            //  if the token is not a binary operator, then 
            //  it is either a variable or an unary operand as a whole
            //  then we just push it into stack
            postfix.push_back(i);
        } else {
            if (i == "(") {
                //  if the token is a left parenthesis, it has the highest precedence
                //  we just push it into operator stack
                opStack.push(i);
            } else if (i == ")") {
                //  if the token is a right parenthesis, we pop all the operators
                //  until we meet the left parenthesis
                while (!opStack.empty() && opStack.top() != "(") {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                //  don't forget to pop the left parenthesis
                opStack.pop();
            } else {
                //  if we meet a binary operator, we pop the operators in the stack 
                //  until we meet an operator with higher precedence
                while (!opStack.empty() && Precedence(i) <= Precedence(opStack.top())) {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                //  don't forget to push the operator into the stack
                opStack.push(i);
            }
        }
    }

    //  finally, we pop all the operators remaining in the stack
    while (!opStack.empty()) {
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    //  construct the expression tree from the postfix expression
    for (auto i : postfix) {
        if (!isBinaryOperator(i)) {
            //  if the token is not a binary operator, then
            //  it is either a variable or an unary operand as a whole
            if (isVariable(i) || isConstant(i)) {
                //  common variable or constant, construct a children node (operand)
                treeStack.push(new Tree(i));
            } else {
                //  look into the unary operator and analyze the details
                //  we construct a father node (operator) with only the left child (operand)
                //  and the right child will be nullptr
                if (i[0] == '#') {
                    //  if the token is a unary minus operator
                    //  we use "neg" to differentiate it from the binary minus operator
                    vector<string> temp = Tokenize(i.substr(1));
                    //  recursively call the function to construct the expression tree
                    //  inside the unary operator
                    Tree *tempTree = parseExpression(temp);
                    Tree *op = new Tree("neg", tempTree, nullptr);
                    treeStack.push(op);
                } else if (i.substr(0, 2) == "ln") {
                    vector<string> temp = Tokenize(i.substr(2));
                    Tree *tempTree = parseExpression(temp);
                    Tree *op = new Tree("ln", tempTree, nullptr);
                    treeStack.push(op);
                } else if (i.substr(0, 3) == "exp" || i.substr(0, 3) == "sin" || 
                           i.substr(0, 3) == "cos" || i.substr(0, 3) == "tan") {
                    vector<string> temp = Tokenize(i.substr(3));
                    Tree *tempTree = parseExpression(temp);
                    Tree *op = new Tree(i.substr(0, 3), tempTree, nullptr);
                    treeStack.push(op);
                } else if (i.substr(0, 3) == "log" || i.substr(0, 3) == "pow") {
                    //  Note that log and pow are very special cases
                    //  they are two unary operators with two operands

                    //  the position of the current token
                    int pos = 4;    //  4 : the position after the first '('
                    int count = 1;  //  count the number of '(' and ')'

                    //  find the position of the comma
                    //  we have to skip the parenthesis pairs inside the operands
                    while (count != 1 || i[pos] != ',') {
                        if (i[pos] == '(') {
                            count++;
                        } else if (i[pos] == ')') {
                            count--;
                        }
                        pos++;
                    }
                    //  expression tree of two operands
                    //  same process : tokenize and expression tree construction
                    vector<string> temp1 = Tokenize(i.substr(4, pos - 4));
                    vector<string> temp2 = Tokenize(i.substr(pos + 1, i.size() - pos - 2));
                    Tree *tempTree1 = parseExpression(temp1);
                    Tree *tempTree2 = parseExpression(temp2);
                    Tree *op = new Tree(i.substr(0, 3), tempTree1, tempTree2);
                    treeStack.push(op);
                }
            }
            
        } else {
            //  if the token is a binary operator, then
            //  we pop two operands from the stack and construct a new node
            Tree* right = treeStack.top();
            treeStack.pop();
            Tree* left = treeStack.top();
            treeStack.pop();

            Tree* op = new Tree(i);
            op->left = left;
            op->right = right;

            treeStack.push(op);     //  push the new node into the stack
        }
    }
    //  the root of the final expression tree will be at the top of the stack
    return treeStack.top();
}

/************************
 * getVariable
 * **********
 * This function will get all the variables in the expression tree
 * and store them in a vector
*/
void getVariable(Tree* root, vector<string>& variables) {
    if (root == nullptr) {
        return;
    }

    //  if the node is a variable, then we push it into the vector
    if (isVariable(root->value)) {
        variables.push_back(root->value);
    }

    //  recursive calls
    getVariable(root->left, variables);
    getVariable(root->right, variables);
}

/************************
 * removeDuplicate
 * **************
 * This function will remove the duplicate variables in the vector
*/
void removeDuplicate(vector<string>& tokens) {
    //  sort the vector and the duplicate variables will be adjacent
    sort(tokens.begin(), tokens.end());
    //  remove the duplicate variables
    //  unique() will select all duplicate variables and move them to the end of the vector
    //  then it will return the position of the first duplicate variable
    //  erase() will delete all the duplicate variables
    tokens.erase(unique(tokens.begin(), tokens.end()), tokens.end());
}

/*****************************
 * printTree
 * *********
 * This function will print the expression tree
*/
void printTree(Tree* root, Tree* parent) {
    //  If the node is non-empty, then we print it
    //  If not, we do nothing
    if (root) {
        if (root->value == "log") {
            //  Format : log(a, b)
            if (root->left->value == "e") {
                //  if the base is e, then we print ln
                cout << "ln(";
                printTree(root->right, root);
                cout << ")";
            } else {
                cout << "log(";
                printTree(root->left, root);
                cout << ",";
                printTree(root->right, root);
                cout << ")";
            }  
        } else if (root->value == "ln") {
            //  Format : ln(a)
            cout << "ln(";
            printTree(root->left, root);
            cout << ")";
        } else if (root->value == "pow") {
            //  Format : pow(a, b)
            cout << "pow(";
            printTree(root->left, root);
            cout << ",";
            printTree(root->right, root);
            cout << ")";
        } else if (root->value == "sin" || root->value == "cos" || 
                   root->value == "tan" || root->value == "sec") {
            //  Format : sin(a), cos(a), tan(a), sec(a)
            cout << root->value << "(";
            printTree(root->left, root);
            cout << ")";
        } else if (root->value == "exp") {
            //  Format : e^(a)
            cout << "e^(";
            printTree(root->left, root);
            cout << ")";
        } else if (root->value == "neg") {
            //  Format : -(a)
            cout << "-(";
            printTree(root->left, root);
            cout << ")";
        } else {
            //  When dealing with parenthesis, we have to check 
            //  the precedence of the parent node and the current node
            //  If the precedence of the parent node is higher
            //  But the operation of the current node comes first
            //  A parenthesis is needed to guarantee validity

            //  Format : (a op b)
            if (checkParenthesis(parent, root)) {
                cout << "(";
            }
            printTree(root->left, root);
            cout << root->value;
            printTree(root->right, root);
            if (checkParenthesis(parent, root)) {
                cout << ")";
            }
        }
    }
}

int main() {
    while (1) {
        //  read in the expression
        string expression;
        cout << "Please input the expression:" << endl;
        cin >> expression;

        //  tokenize the expression
        vector<string> tokens = Tokenize(expression);
        // cout << "Successful tokenization!" << endl;

        //  construct the expression tree and do simplification
        Tree *root = parseExpression(tokens);
        // cout << "Successful tree construction!" << endl;
        // cout << "original expression: ";
        // printTree(simplifyTree(root), nullptr);
        // cout << endl;

        //  find all variables in the expression
        vector<string> variables;
        getVariable(root, variables);
        removeDuplicate(variables);
        // cout << "Successful variable getting!" << endl;
        // cout << "Here are the variables: ";
        // for (auto i : variables) {
        //     cout << i << " ";
        // }
        // cout << endl;
        
        //  iterate through all variables and do auto differentiation
        //  i : variable iterator
        for (auto i : variables) {
            Tree *result = autoGrad(simplifyTree(root), i, variables);
            cout << i << " : ";
            // printTree(result, nullptr);
            // cout << endl;
            printTree(simplifyTree(result), nullptr);
            // printTree(result, nullptr);
            cout << endl;
        }

        cout << endl;
    }
    return 0;
}