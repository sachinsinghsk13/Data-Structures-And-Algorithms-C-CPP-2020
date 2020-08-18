#include "btree.h"
#include <iostream>

BTreeNode::BTreeNode(int t, bool leaf)
{
    this->t = t;
    this->leaf = leaf;

    keys = new int[2 * t - 1];
    childs = new BTreeNode *[2 * t];
    n = 0;
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!leaf)
            childs[i]->traverse();
        std::cout << keys[i] << " ";
    }

    if (!leaf)
        childs[i]->traverse();
}

BTreeNode *BTreeNode::search(int key)
{
    int i = 0;
    while (i < n && key > keys[i])
        i++;
    if (key == keys[i])
        return this;
    if (leaf)
        return nullptr;
    return childs[i]->search(key);
}

void BTreeNode::insertNonFull(int key)
{
    int i = n - 1;
    if (leaf)
    {
        while (i >= 0 && keys[i] > key)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i] = key;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > key)
            i--;
        if (childs[i + 1]->n == 2 * t - 1)
        {
            splitChild(i + 1, childs[i + 1]);

            if (keys[i + 1] < key)
                i++;
        }
        childs[i + 1]->insertNonFull(key);
    }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->childs[j] = y->childs[j + t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i + 1; j--)
        childs[j + 1] = childs[j];

    // Link the new child to this node
    childs[i + 1] = z;

    // A key of y will move to this node. Find the location of
    // new key and move all greater keys one space ahead
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Copy the middle key of y to this node
    keys[i] = y->keys[t - 1];

    // Increment count of keys in this node
    n = n + 1;
}

BTree::BTree(int t)
{
    this->t = t;
    root = nullptr;
}

void BTree::traverse()
{
    if (root)
        root->traverse();
}

BTreeNode *BTree::search(int key)
{
    if (root)
        return root->search(key);
    return nullptr;
}

void BTree::insert(int key)
{
    if (!root)
    {
        root = new BTreeNode(t, true);
        root->keys[0] = key;
        root->n = 1;
    }
    else
    {
        // If root is full, then tree grows in height
        if (root->n == 2 * t - 1)
        {
            // Allocate memory for new root
            BTreeNode *s = new BTreeNode(t, false);

            // Make old root as child of new root
            s->childs[0] = root;

            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);

            // New root has two children now. Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0] < key)
                i++;
            s->childs[i]->insertNonFull(key);

            // Change root
            root = s;
        }
        else // If root is not full, call insertNonFull for root
            root->insertNonFull(key);
    }
}