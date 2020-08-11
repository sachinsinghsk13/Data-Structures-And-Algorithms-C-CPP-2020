#include "threaded-binary-search-tree.h"
#include <iostream>

ThreadedNode::ThreadedNode() {
    key = 0;
    left = right = nullptr;
    lthread = rthread = true;
}

ThreadedNode::~ThreadedNode() {}

ThreadedBST::ThreadedBST() {
    root = nullptr;
}

ThreadedBST::~ThreadedBST() {}

void ThreadedBST::insert(int key) {
    root = insert(root, key);
}

ThreadedNode *ThreadedBST::insert(ThreadedNode *loc, int key) {
    ThreadedNode *ptr = root, *parent = nullptr;
    while (ptr) {
        if (ptr->key == key) {
            std::cout << "Duplicate key" << std::endl;
            return root;
        }
        parent = ptr;

        if (key < ptr->key) {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }

        else {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }
    // create new node
    ThreadedNode *node = new ThreadedNode();
    node->key = key;

    if (!parent) {
        root = node;
    }

    else if (key < parent->key) {
        node->left = parent->left;
        node->right = parent;
        parent->lthread = false;
        parent->left = node;
    }

    else {
        node->right = parent->right;
        node->left = parent;
        parent->rthread = false;
        parent->right = node;
    }
    return root;
}

ThreadedNode *ThreadedBST::inorderSuccessor(ThreadedNode *loc) {
    if (loc->rthread)
        return loc->right;
    else {
        loc = loc->right;
        while (!loc->lthread)
            loc = loc->left;
        return loc;
    }
}

void ThreadedBST::inorder() {
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    ThreadedNode *ptr = root;
    while (!ptr->lthread)
        ptr = ptr->left;

    while (ptr) {
        std::cout << ptr->key << " ";
        ptr = inorderSuccessor(ptr);
    }

    std::cout<< std::endl;
}