# include <iostream>
# include <queue>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
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
	else if(btree->data == newnode->data)
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

int distanceFromRoot(node* newnode,int x)
{
	if(x < newnode->data)
	{
		return 1 + distanceFromRoot(newnode->left,x);
	}
	else if(x > newnode->data)
	{
		return 1 + distanceFromRoot(newnode->right,x);
	}

	return 0;
}

int distanceBetween2Node(node* newnode,int x,int y)
{
	if(newnode == NULL)
	{
		return 0;
	}

	if(x > y)
	{
		swap(x,y);
	}

	if(x < newnode->data && y < newnode->data)
	{
		return distanceBetween2Node(newnode->left,x,y);
	}

	if(x > newnode->data && y > newnode->data)
	{
		return distanceBetween2Node(newnode->right,x,y);
	}

	if(x <= newnode->data && y >= newnode->data)
	{
		return distanceFromRoot(newnode,x) + distanceFromRoot(newnode,y);
	}

	return 0;
}

int main()
{
	node* btree = createBtree();
	int x,y;

	x = 3;y = 9;
	cout << "distanceBetween2Node(" << x << "," << y << ") => " << distanceBetween2Node(btree,x,y) << endl;
	x = 3;y = 6;
	cout << "distanceBetween2Node(" << x << "," << y << ") => " << distanceBetween2Node(btree,x,y) << endl;

	return 0;
}
