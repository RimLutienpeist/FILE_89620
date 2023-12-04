#ifndef _AUTOGRAD_H_
#define _AUTOGRAD_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "tree.hpp"
#include "check.hpp"

using namespace std;

Tree* autoGrad(Tree* root, const string& var, const vector<string>& variables);

Tree* simplifyTree(const Tree* root);

#endif