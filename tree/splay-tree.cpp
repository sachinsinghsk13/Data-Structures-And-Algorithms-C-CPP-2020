#include "splay-tree.h"
#include <iostream>
using namespace std;

stnode::stnode(int key, int value) {
    this->key = key;
    this->value = value;
    left = right = nullptr;
}

splay_tree::splay_tree() {
    root = nullptr;
}

stnode *splay_tree::rotate_left(stnode *node) {
    stnode *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    return new_root;
}

stnode *splay_tree::rotate_right(stnode *node) {
    stnode *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    return new_root;
}

stnode *splay_tree::insert(stnode *loc, int key, int value) {
    if (!loc)
        return new stnode(key, value);
    else if (key < loc->key) {
        loc->left = insert(loc->left, key, value);
        return rotate_right(loc);
    }
    else {
        loc->right = insert(loc->right, key, value);
        return rotate_left(loc);
    }
}

int splay_tree::get_top() {
    if (root)
        return root->value;
    return -1;
}

stnode *splay_tree::search(stnode *loc, int key) {
    if (!loc)
        return nullptr;
    else if (key == loc->key)
        return loc;
    else if (key < loc->key) {
        loc->left = search(loc->left, key);
        return rotate_right(loc);
    }
    else
    {
        loc->right = search(loc->right, key);
        return rotate_left(loc);
    }
}

void splay_tree::insert(int key, int value) {
    root = insert(root, key, value);
}

int splay_tree::search(int key) {
    root = search(root, key);
    return root->value;
}