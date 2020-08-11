#ifndef __TBST__
#define __TBST__

class ThreadedNode {
    public:
        ThreadedNode();
        ~ThreadedNode();
        int key;
        ThreadedNode *left, *right;
        bool lthread, rthread;
};

class ThreadedBST {
    private:
        ThreadedNode *root;
        ThreadedNode *insert(ThreadedNode *loc, int key);
        ThreadedNode *inorderSuccessor(ThreadedNode *loc);
    public:
        ThreadedBST();
        ~ThreadedBST();
        void insert(int key);
        void inorder();
};

#endif