#include "binary-search-tree.h"
#include <iostream>

Node::Node()
{
    key = 0;
    left = right = nullptr;
}

Node::Node(int key)
{
    this->key = key;
    left = right = nullptr;
}

Node::~Node() {}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int key)
{
    insert(root, key);
}
/*
    Method for recursively inserting a key
*/
Node *BinarySearchTree::insert(Node *loc, int key)
{
    if (root != nullptr)
    {
        if (loc == nullptr)
            loc = new Node(key);
        else if (key < loc->key)
            loc->left = insert(loc->left, key);
        else
            loc->right = insert(loc->right, key);
        return loc;
    }
    else
        root = new Node(key);
}

void BinarySearchTree::inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void BinarySearchTree::inorder()
{
    inorder(root);
}

void BinarySearchTree::postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->key << " ";
    }
}

void BinarySearchTree::postorder()
{
    postorder(root);
}

void BinarySearchTree::preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BinarySearchTree::preorder()
{
    preorder(root);
}
