#include "avl-tree.h"
#include <iostream>

AVLNode::AVLNode()
{
    key = 0;
    left = right = nullptr;
    height = 0;
}
AVLNode::AVLNode(int key)
{
    this->key = key;
    left = right = nullptr;
    height = 0;
}

AVLNode::~AVLNode() {}

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree() {}

int AVLTree::getHeight(AVLNode *node)
{
    if (node)
        return node->height;
    return -1;
}

void AVLTree::setHeight(AVLNode *node)
{
    if (node != nullptr)
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int AVLTree::getBalanceFactor(AVLNode *node)
{
    if (node)
        return getHeight(node->left) - getHeight(node->right);
    return 0;
}

AVLNode *AVLTree::rotateLeft(AVLNode *root)
{
    AVLNode *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    // update height
    setHeight(root);
    setHeight(newRoot);
    return newRoot;
}

AVLNode *AVLTree::rotateRight(AVLNode *root)
{
    AVLNode *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    // update height
    setHeight(root);
    setHeight(newRoot);
    return newRoot;
}

void AVLTree::insert(int key)
{
    root = insert(root, key);
}

AVLNode *AVLTree::insert(AVLNode *loc, int key)
{
    if (!loc)
        return new AVLNode(key);
    else if (key < loc->key)
        loc->left = insert(loc->left, key);
    else
        loc->right = insert(loc->right, key);

    setHeight(loc); // update height of this node

    int balanceFactor = getBalanceFactor(loc);

    // case: RL
    if (balanceFactor < -1 && key < loc->right->key)
    {
        loc->right = rotateRight(loc->right);
        loc = rotateLeft(loc);
    }

    // case: RR
    else if (balanceFactor < -1 && key > loc->right->key)
    {
        loc = rotateLeft(loc);
    }

    // case: LL
    else if (balanceFactor > 1 && key < loc->key)
    {
        loc = rotateRight(loc);
    }

    // case: LR
    else if (balanceFactor > 1 && key > loc->key)
    {
        loc->left = rotateLeft(loc->left);
        loc = rotateRight(loc);
    }

    return loc;
}

void AVLTree::inorder(AVLNode *root)
{
    if (root)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void AVLTree::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

AVLNode *AVLTree::getMaximumKeyNode(AVLNode *node)
{
    if (node->right)
        return node->right;
    return node;
}

void AVLTree::remove(int key)
{
    root = remove(root, key);
}

AVLNode *AVLTree::remove(AVLNode *loc, int key)
{
    if (!loc)
    {
        std::cout << "Key Not Found " << std::endl;
        return nullptr;
    }
    else if (key == loc->key)
    {
        if (!loc->right && !loc->left)
        {
            delete loc;
            return nullptr;
        }
        else if (!loc->right && loc->left)
        {
            AVLNode *temp = loc->left;
            delete loc;
            return temp;
        }

        else if (loc->right && !loc->left)
        {
            AVLNode *temp = loc->right;
            delete loc;
            return temp;
        }

        else
        {
            AVLNode *leftMaxNode = getMaximumKeyNode(loc->left);
            loc->key = leftMaxNode->key;
            loc->left = remove(loc->left, leftMaxNode->key);
            return loc;
        }
    }
    else if (key < loc->key)
        loc->left = remove(loc->left, key);
    else
        loc->right = remove(loc->right, key);

    setHeight(loc);

    int balanceFactor = getBalanceFactor(loc);

    if (balanceFactor > 1)
    {
        int leftSubTreeBalanceFactor = getBalanceFactor(loc->left);
        switch (leftSubTreeBalanceFactor)
        {
        case 0:
        case 1:
            loc = rotateRight(loc);
            break;
        case -1:
            loc->left = rotateLeft(loc->left);
            loc = rotateRight(loc);
        }
    }

    else if (balanceFactor < -1)
    {
        int rightSubTreeBalanceFactor = getBalanceFactor(loc->right);
        switch (rightSubTreeBalanceFactor)
        {
        case 0:
        case 1:
            loc = rotateLeft(loc);
            break;
        case -1:
            loc->right = rotateRight(loc->right);
            loc = rotateLeft(loc);
            break;
        }
    }
    return loc;
}
