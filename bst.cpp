#include<iostream>

using namespace std;

class BinarySearchTree
{
	struct node
	{
		int data;
		node* left;
		node* right;
	};

	node* root;
	
	//make a tree empty
	node* makeEmpty(node* t)
	{
		if(t == NULL)
			return NULL;
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	node* insert(int x, node* t)
	{
		if(t == NULL)
		{
			t = new node;
			t->data = x;
			//initialization
			t->left = t->right = NULL;
		}
		else if(x < t->data)
			t->left = insert(x, t->left);
		else if(x > t->data)
			t->right = insert(x, t->right);
		return t;
	}

	node* findMin(node* t)
	{
		if(t == NULL)
			return NULL;
		else if(t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t)
	{
		if(t == NULL)
			return NULL;
		else if(t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(int x, node* t)
	{
		node* tmp;
		if(t == NULL)
			return NULL;
		//moving downward
		else if(x < t->data)
			t->left = remove(x, t->left);
		else if(x > t->data)
			t->right = remove(x, t->right);
		// x = t->data & t->left, t->right are NULL
		else if(t->left && t->right)
		{
			tmp = findMin(t->right);
			t->data = tmp->data;
			t->right = remove(t->data, t->right);
			//tmp = findMax(t->left);
			//t->data = tmp->data;
			//t->left = remove(t->data, t->left);
		}
		// x = t->data & t->left or t->right are NULL
		else
		{
			tmp = t;
			if(t->left == NULL)
				t = t->right;
			else if(t->right == NULL)
				t = t->left;
			delete tmp;
		}
	
		return t;
	}
	
	void inorder(node* t)
	{
		if(t == NULL)
			return;
		// LVR inorder
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}
	
	void preorder(node* t)
	{
		if(t == NULL)
			return;
		// VLR preorder
		cout << t->data << " ";
		preorder(t->left);
		preorder(t->right);
	}

	void postorder(node* t)
	{
		if(t == NULL)
			return;
		// LRV postorder
		postorder(t->left);
		postorder(t->right);
		cout << t->data << " ";
	}

	node* find(node* t, int x)
	{
		if(t == NULL)
			return NULL;
		else if(x < t->data)
			return find(t->left, x);
		else if(x > t->data)
			return find(t->right, x);
		// x = t->data
		else
			return t;
	}

public:
	BinarySearchTree()
	{
		root = NULL;
	}
	
	~BinarySearchTree()
	{
		root = makeEmpty(root);
	}

	void insert(int x)
	{
		root = insert(x, root);
	}

	void remove(int x)
	{
		root = remove(x, root);
	}

	void display(char flag)
	{
		if(flag=='i')
			inorder(root);
		else if(flag=='r')
			preorder(root);
		else if(flag=='t')
			postorder(root);
		cout << endl;
	}

	void search(int x)
	{
		root = find(root, x);
	}
};

int main()
{
	BinarySearchTree t;
	t.insert(20);
	t.insert(20);
	t.insert(25);
	t.insert(15);
	t.insert(10);
	t.insert(30);
	t.display('r');
	t.remove(20);
	t.display('r');
	t.remove(25);
	t.display('r');
	t.remove(30);
	t.display('r');
}
