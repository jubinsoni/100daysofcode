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

void inorder(node* newnode)
{
	if(newnode != NULL)
	{
		inorder(newnode->left);
		cout << newnode->data << " ";
		inorder(newnode->right);	
	}
}

void preorder(node* newnode)
{
	if(newnode != NULL)
	{
		cout << newnode->data << " ";
		preorder(newnode->left);
		preorder(newnode->right);
	}
}


void postorder(node* newnode)
{
	if(newnode != NULL)
	{
		postorder(newnode->left);
		postorder(newnode->right);
		cout << newnode->data << " ";
	}
}

void levelorder(node* newnode)
{
	queue<node*> q;
	q.push(newnode);
	while(q.empty() == false)
	{
		node* curr = q.front();
		cout << curr->data << " ";
		q.pop();
		if(curr->left != NULL)
		{
			q.push(curr->left);			
		}
		if(curr->right != NULL)
		{
			q.push(curr->right);			
		}
	}
}

int main()
{
	node* btree = createBtree();
	cout << "inorder Traversal => ";
	inorder(btree);
	cout << endl;
	cout << "preorder Traversal => ";
	preorder(btree);
	cout << endl;
	cout << "postorder Traversal => ";
	postorder(btree);
	cout << endl;
	cout << "levelorder Traversal => ";
	levelorder(btree);
	cout << endl;
	return 0;
}






