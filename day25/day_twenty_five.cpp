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

int maxWidth(node* newnode)
{
	queue<node*> q;
	q.push(newnode);
	int max_size = 0;
	while(q.empty() == false)
	{
		if(max_size < q.size())
		{
			max_size = q.size();
		}

		node* temp = q.front();
		q.pop();

		if(temp->left != NULL)
		{
			q.push(temp->left);
		}

		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
	
	return max_size;
}

int main()
{
	node* btree = createBtree();

	cout << "maxWidth of BianryTree => ";
	cout << maxWidth(btree) << endl;

	return 0;
}