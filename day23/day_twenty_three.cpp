# include <iostream>
# include <queue>
# include <stack>

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

void zigzagTraversal(node* newnode)
{
	stack<node*> currentLevel;
	stack<node*> nextLevel;

	currentLevel.push(newnode);
	int leftToRight = true;

	while(currentLevel.empty() == false)
	{
		node* temp = currentLevel.top();
		currentLevel.pop();

		if(temp != NULL)
		{
			cout << temp->data << " ";
			if(leftToRight == true)
			{
				if(temp->left != NULL)
				{
					nextLevel.push(temp->left);
				}

				if(temp->right != NULL)
				{
					nextLevel.push(temp->right);
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					nextLevel.push(temp->right);
				}

				if(temp->left != NULL)
				{
					nextLevel.push(temp->left);
				}
			}
		}

		if(currentLevel.empty() == true)
		{
			leftToRight = !leftToRight;
			swap(currentLevel,nextLevel);
		}
	}

}

int main()
{
	node* btree = createBtree();
	cout << "zigzag Traversal => ";
	zigzagTraversal(btree);
	cout << endl;
	return 0;
}