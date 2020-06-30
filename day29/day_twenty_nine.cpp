# include <iostream>
# include <queue>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* getNode()
{
	node* newnode = (node*)malloc(sizeof(node));
	return newnode;
}

void readNode(node* newnode,int data)
{
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

node* createTree(int arr[])
{
	node* tree = NULL;
	node* newnode = getNode();
	readNode(newnode,arr[0]);
	if(tree == NULL)
	{
		tree = newnode;
	}
	tree->left = getNode();
	readNode(tree->left,arr[1]);

	tree->right = getNode();
	readNode(tree->right,arr[2]);

	tree->left->left = getNode();
	readNode(tree->left->left,arr[3]);

	tree->left->right = getNode();
	readNode(tree->left->right,arr[4]);

	tree->right->left = getNode();
	readNode(tree->right->left,arr[5]);

	tree->right->right = getNode();
	readNode(tree->right->right,arr[6]);

	return tree;
}

void levelOrderTraversal(node* newnode)
{
	queue<node*> q;
	q.push(newnode);
	while(q.empty() == false)
	{
		node* temp = q.front();
		cout << temp->data << " ";
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
}

bool isChildrenSum(node* curr)
{
	if(curr == NULL)
	{
		return true;
	}

	if(curr->left == NULL && curr->right == NULL)
	{
		return true;
	}

	int sum = 0;
	if(curr->left != NULL)
	{
		sum = sum + curr->left->data;
	}

	if(curr->right != NULL)
	{
		sum = sum + curr->right->data;
	}

	if(curr->data == sum && isChildrenSum(curr->left) == true && isChildrenSum(curr->right) == true)
	{
		return true;
	}

	return false;
}

int main()
{
	int arr1[] = {20,8,12,3,5,2,10};
	node* tree1 = createTree(arr1);

	cout << "levelOrderTraversal => ";
	levelOrderTraversal(tree1);
	cout << endl;

	cout << "follows children sum property => ";
	cout << isChildrenSum(tree1) << endl;

	int arr2[] = {7,5,10,3,6,9,12};
	node* tree2 = createTree(arr2);

	cout << "levelOrderTraversal => ";
	levelOrderTraversal(tree2);
	cout << endl;

	cout << "follows children sum property => ";
	cout << isChildrenSum(tree2) << endl;

	return 0;
}