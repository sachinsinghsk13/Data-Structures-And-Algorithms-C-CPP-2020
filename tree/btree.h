#ifndef __B_TREE__
#define __B_TREE__

class BTreeNode
{
private:
    int *keys;
    int t;
    BTreeNode **childs;
    int n;
    bool leaf;
public:
    BTreeNode(int t, bool leaf);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int key);
    friend class BTree;
};

class BTree {
    private:
        BTreeNode *root;
        int t;
    public:
        BTree(int t);
        void traverse();
        BTreeNode *search(int key);
        void insert(int key);
};

#endif

/*

class BTreeNode
{
private:
	int *keys;
	int total_keys;
	int mininum_degree;
	BTreeNode **childs;
	bool leaf;

public:
	BTreeNode(int mininum_degree, bool leaf);
	void insertNotFull(int key);
	void splitChild(int i, BTreeNode *y);
	void traverse();
	BTreeNode *search(int key);
	friend class BTree;
};

class BTree
{
private:
	BTreeNode *root;
	int mininum_degree;

public:
	BTree(int degree);
	void insert(int key);
	void traverse();
	BTreeNode *search(int key);
};

BTreeNode::BTreeNode(int minimum_degree, bool leaf)
{
	this->mininum_degree = minimum_degree;
	this->leaf = leaf;

	keys = new int[2 * minimum_degree - 1];
	childs = new BTreeNode *[2 * minimum_degree];
	total_keys = 0;
}

void BTreeNode::traverse()
{
	int i;
	for (i = 0; i < total_keys; i++)
	{
		if (!leaf)
			childs[i]->traverse();
		cout << keys[i] << " ";
	}
	if (!leaf)
		childs[i]->traverse();
}

BTreeNode *BTreeNode::search(int key)
{
	int i = 0;

	while (i < total_keys && key > keys[i])
		i++;
	if (key == keys[i])
		return this;
	if (leaf)
		return nullptr;
	return childs[i]->search(key);
}

void BTree::insert(int key)
{
	if (root == nullptr)
	{
		root = new BTreeNode(mininum_degree, true);
		root->keys[0] = key;
		root->total_keys = 1;
	}
	else
	{
		if (root->total_keys == 2 * mininum_degree - 1)
		{
		}
		else
		{
			root->insertNotFull(key);
		}
	}
}

void BTreeNode::insertNotFull(int key) {
	int i = total_keys - 1;

	if (leaf) {
		while (i >= 0 && key < keys[i]) {
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = key;
		total_keys++;
	}
	else
	{
		while (i >= 0 && key < keys[i])
			i--;
		if (childs[i + 1]->total_keys == 2 * mininum_degree - 1) {
			splitChild(i + 1, childs[i + 1]);

			if (keys[i + 1] < key)
				i++;
		}
		childs[i + 1]->insertNotFull(key);
		
	}
	
}



*/