#include "red-black-tree.h"
#include <iostream>

RBNode::RBNode()
{
    key = 0;
    left = right = parent = nullptr;
    color = RED;
}

RBNode::RBNode(int key)
{
    this->key = key;
    left = right = parent = nullptr;
    color = RED;
}

RBNode::~RBNode() {}

RBTree::RBTree()
{
    root = nullptr;
}

RBTree::~RBTree() {}

RBNode *RBTree::get_grandparent(RBNode *node)
{
    if (node && node->parent && node->parent->parent)
        return node->parent->parent;
    return nullptr;
}

RBNode *RBTree::get_uncle(RBNode *node)
{
    RBNode *g = get_grandparent(node);
    if (g)
    {
        if (g->left == node->parent)
            return g->right;
        return g->left;
    }
    return nullptr;
}

Color RBTree::get_color(RBNode *node)
{
    if (node)
        return node->color;
    return BLACK;
}

void RBTree::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

void RBTree::inorder(RBNode *root)
{
    if (root)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void RBTree::rotateLeft(RBNode *current_root)
{
    RBNode *newRoot = current_root->right;
    // current_root is not root of RBTree
    if (current_root->parent)
    {
        if (current_root->parent->left == current_root)
            current_root->parent->left = newRoot;
        else
            current_root->parent->right = newRoot;
    }
    // current_root is root of the Tree
    else
    {
        root = newRoot;
    }
    newRoot->parent = current_root->parent;
    current_root->right = newRoot->left;
    if (newRoot->left)
        newRoot->left->parent = root;
    newRoot->left = current_root;
    current_root->parent = newRoot;
}

void RBTree::rotateRight(RBNode *current_root)
{
    RBNode *newRoot = current_root->left;
    // current_root is not root of RBTree
    if (current_root->parent)
    {
        if (current_root->parent->left == current_root)
            current_root->parent->left = newRoot;
        else
            current_root->parent->right = newRoot;
    }
    // current_root is root of the Tree
    else
    {
        root = newRoot;
    }
    newRoot->parent = current_root->parent;
    current_root->left = newRoot->right;
    if (newRoot->right)
        newRoot->right->parent = root;
    newRoot->right = current_root;
    current_root->parent = newRoot;
}

void RBTree::swap_color(RBNode *a, RBNode *b)
{
    Color tmp = a->color;
    a->color = b->color;
    b->color = tmp;
}

void RBTree::insert(int key)
{
    RBNode *node = new RBNode(key);
    root = standard_BST_insert(root, node);
    restore_red_black_restrictions(node);
}

RBNode *RBTree::standard_BST_insert(RBNode *loc, RBNode *node)
{
    if (!loc)
        return node;
    else if (node->key < loc->key)
    {
        RBNode *tmp = standard_BST_insert(loc->left, node);
        loc->left = tmp;
        tmp->parent = loc;
    }
    else
    {
        RBNode *tmp = standard_BST_insert(loc->right, node);
        loc->right = tmp;
        tmp->parent = loc;
    }
    return loc;
}

void RBTree::restore_red_black_restrictions(RBNode *node)
{
    if (node == root)
    {
        node->color = BLACK;
    }
    else if (node->parent->color == RED)
    {
        RBNode *uncle = get_uncle(node);
        if (get_color(uncle) == RED)
        {
            node->parent->color = uncle->color = BLACK;
            RBNode *grandparent = get_grandparent(node);
            grandparent->color = RED;
            restore_red_black_restrictions(grandparent);
        }
        else
        {
            RBNode *granparent = get_grandparent(node);
            if (node->parent->key < granparent->key)
            {
                // LL case
                if (node->key < node->parent->key)
                {
                    swap_color(node->parent, granparent);
                    rotateRight(granparent);
                }
                // LR case
                else
                {
                    swap_color(node, granparent);
                    rotateLeft(node->parent);
                    rotateRight(granparent);
                }
            }
            else
            {
                // RL case
                if (node->key < node->parent->key)
                {
                    swap_color(node, granparent);
                    rotateRight(node->parent);
                    rotateLeft(granparent);
                }
                // RR
                else
                {
                    swap_color(node->parent, granparent);
                    rotateLeft(granparent);
                }
            }
        }
    }
}