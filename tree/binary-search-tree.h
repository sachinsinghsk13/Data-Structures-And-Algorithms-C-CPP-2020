#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

class Node
{
public:
    int key;
    Node *left, *right;
    Node();
    Node(int key);
    ~Node();
};

class BinarySearchTree
{
private:
    Node *root;
    Node *insert(Node *loc, int key);
    void inorder(Node *root);
    void preorder(Node *root);
    void postorder(Node *root);
    int height(Node *loc);
    Node *remove(Node *loc, int key);
    Node *find_lowest(Node *loc);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int key);
    void remove(int key);
    void removeIterative(int key);
    void inorder();
    void preorder();
    int height();
    void postorder();
    void bfs();
};

#endif