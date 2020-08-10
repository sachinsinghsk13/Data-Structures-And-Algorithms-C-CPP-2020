#include "binary-search-tree.h"
#include <iostream>
#include <stack>
#include <queue>

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
    // insert(root, key);  /*  for insert by recursion and comment the iterative process*/

    // Iterative process for inserting..

    if (root != nullptr)
    {
        Node *current = root, *parent = root;
        while (current != nullptr)
        {
            parent = current;
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }

        if (key < parent->key)
            parent->left = new Node(key);
        else
            parent->right = new Node(key);
    }
    else
    {
        root = new Node(key);
    }
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
    //inorder(root); // for recursive method

    // Iterative method of traversal using stack.
    Node *temp = root;
    std::stack<Node *> s;
    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        std::cout << temp->key << " ";
        temp = temp->right;
    }
    std::cout << std::endl;

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
    Node *temp = root;
    std::stack<Node *> s;
    std::stack<char> flags;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            flags.push('L');
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        char f = flags.top();
        flags.pop();
        if (f == 'L')
        {
            s.push(temp);
            flags.push('R');
            temp = temp->right;
        }
        else
        {
            std::cout << temp->key << " ";
            temp = nullptr;
        }
    }
    std::cout << std::endl;
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
    // preorder(root);
    Node *temp = root;
    std::stack<Node *> s;
    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            std::cout << temp->key << " ";
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        temp = temp->right;
    }
    std::cout << std::endl;
}

void BinarySearchTree::bfs()
{
    Node *temp = root;
    std::queue<Node *> q;

    while (temp != nullptr || !q.empty())
    {
        if (temp != nullptr)
        {
            std::cout << temp->key << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            temp = nullptr;
        }
        else
        {
            temp = q.front();
            q.pop();
        }
    }
    std::cout << std::endl;
}

Node *BinarySearchTree::find_lowest(Node *loc) {
    if (loc->left)
        return find_lowest(loc->left);
    return loc;
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
}

Node *BinarySearchTree::remove(Node *loc, int key) {
    if (loc) {
        if (key == loc->key) {
            if (!loc->right && !loc->left) { // leaf node
                delete loc;
                return nullptr;
            }
            else if (loc->right && !loc->left) { // node have only right child
                Node *temp = loc->right;
                delete loc;
                return temp;
            }
            else if (!loc->right && loc->left) { // node have only left child
                Node *temp = loc->left;
                delete loc;
                return temp;
            }
            else { // node have both child

                // find the lowest key node in right subtree
                Node *lowestKeyNode = find_lowest(loc->right);
                loc->key = lowestKeyNode->key;

                loc->right = remove(loc->right, loc->key);
                return loc;
            }
        }
        else if (key < loc->key) {
            loc->left = remove(loc->left, key);
            return loc;
        }
        else {
            loc->right = remove(loc->right, key);
            return loc;
        }
    }
    else {
        std::cout << "Key Not Found" << std::endl;
    }
}