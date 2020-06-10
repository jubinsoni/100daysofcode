# include <iostream>

using namespace std;

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	int data;
}node;

int itr = 0;
int arr[] = {7,5,10,3,6,9,12};
int size = sizeof(arr)/sizeof(arr[0]);

node* getNode()
{
	node* newnode = (node*)malloc(sizeof(node));
	return newnode;
}

void readNode(node* newnode)
{
	newnode->data = arr[itr];
	itr = itr + 1;
	newnode->left = NULL;
	newnode->right = NULL;
}

node* insertNode(node* btree,node* newnode)
{
	if(btree == NULL)
	{
		return newnode;
	}
	else if(newnode->data < btree->data)
	{
		btree->left = insertNode(btree->left,newnode);
	}
	else if(newnode->data > btree->data)
	{
		btree->right = insertNode(btree->right,newnode);
	}
	else if(newnode->data == btree->data)
	{
		cout << "data already exist" << endl;
		return btree;
	}
	return btree;
}

node* createBtree()
{
	node* btree = NULL;
	for(int i=0;i<size;i++)
	{
		node* newnode = getNode();
		readNode(newnode);
		btree = insertNode(btree,newnode);
	}
	return btree;
}

// O(n)
void inorderTraversal(node* newnode)
{
	if(newnode != NULL)
	{
		inorderTraversal(newnode->left);
		cout << newnode->data << " ";
		inorderTraversal(newnode->right);
	}
}

int main()
{
	node* btree = createBtree();
	inorderTraversal(btree);
	cout << endl;
	return 0;
}