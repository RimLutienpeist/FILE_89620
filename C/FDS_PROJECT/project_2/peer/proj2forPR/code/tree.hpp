#ifndef _TREE_H_
#define _TREE_H_

#include <string>

class Tree {
    public:
        std::string value;
        Tree *left;
        Tree *right;

        //  Default constructor I
        //  Initialize the tree without any children
        Tree(std::string value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }

        //  Default constructor II
        //  Initialize the tree with children
        Tree(std::string value, Tree *left, Tree *right) {
            this->value = value;
            this->left = left;
            this->right = right;
        }
};

#endif