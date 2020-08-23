#ifndef __SPLAY_TREE__
#define __SPLAY_TREE__

class stnode {
    public:
        int key, value;
        stnode *left, *right;
        stnode(int key, int value);
};

class splay_tree {
    private:
        stnode *root;
        stnode *rotate_left(stnode *node);
        stnode *rotate_right(stnode *node);
        stnode *insert(stnode *loc, int key, int value);
        stnode *search(stnode *loc, int key);
    public:
        splay_tree();
        int get_top();
        void insert(int key, int value);
        int search(int key);
};

#endif