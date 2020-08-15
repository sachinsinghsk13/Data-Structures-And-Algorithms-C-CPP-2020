#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__

enum Color
{
    BLACK,
    RED
};

class RBNode
{
public:
    int key;
    RBNode *left, *right, *parent;
    Color color;
    RBNode();
    RBNode(int key);
    ~RBNode();
};

class RBTree
{
    private:
        RBNode *root;
        RBNode *get_grandparent(RBNode* node);
        RBNode *get_uncle(RBNode* node);
        Color get_color(RBNode *node);
        void rotateLeft(RBNode *current_root);
        void rotateRight(RBNode *current_root);
        void swap_color(RBNode *a, RBNode *b);
        RBNode *standard_BST_insert(RBNode *loc, RBNode* node);
        void restore_red_black_restrictions(RBNode *node);
        void inorder(RBNode *root);
    public:
        RBTree();
        ~RBTree();
        void insert(int key);
        void inorder();
};

#endif