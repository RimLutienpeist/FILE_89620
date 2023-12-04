#ifndef _TYPE_H_
#define _TYPE_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "tree.hpp"

using namespace std;

int isValid(const string& token, const int i);

int isVariable(const string& c);

int Precedence(const string& op);

int isUnaryOperator(const string& c, const int i);

int isBinaryOperator(const string& c);

int isConstant(const string& c);

int isPartialVariable(const string& partial, const string& main, const vector<string>& variables);

bool checkConstant(Tree *root, const string& var, const vector<string>& variables);

int unaryExpressionParser(const string& c);

int isomorphicTree(Tree* T1, Tree* T2);

int checkParenthesis(const Tree* parent, const Tree* child);

string calculateConstRes(const string a, const string b, const string op);

#endif