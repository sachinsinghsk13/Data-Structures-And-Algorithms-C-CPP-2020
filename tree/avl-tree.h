#ifndef __AVL_TREE__
#define __AVL_TREE__

class AVLNode {
    public: 
        AVLNode();
        AVLNode(int key);
        ~AVLNode();
        int key;
        AVLNode *left, *right;
        int height;
};

class AVLTree {
    private:
        AVLNode *root;
        AVLNode *insert(AVLNode *loc, int key);
        AVLNode *remove(AVLNode *loc, int key);
        AVLNode *rotateLeft(AVLNode *root);
        AVLNode *rotateRight(AVLNode *root);
        void setHeight(AVLNode *node);
        int getHeight(AVLNode *node);
        int getBalanceFactor(AVLNode *node);
        AVLNode *getMaximumKeyNode(AVLNode *node);
        void inorder(AVLNode *root);
    public:
        AVLTree();
        ~AVLTree();
        void insert(int key);
        void remove(int key);
        void inorder();
};

#endif