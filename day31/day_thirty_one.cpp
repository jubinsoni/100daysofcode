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

bool findpath(node* root,vector<int> &path,int k)
{
	if(root == NULL)
	{
		return false;
	}

	path.push_back(root->data);

	if(root->data == k)
	{
		return  true;
	}

	if(root->left != NULL)
	{
		bool res = findpath(root->left,path,k);
		if(res == true)
		{
			return true;
		}
	}

	if(root->right != NULL)
	{
		bool res = findpath(root->right,path,k);
		if(res == true)
		{
			return true;
		}
	}

	path.pop_back();
	return false;
}

int findLCA(node* root,int x,int y)
{
	vector<int> path1;
	vector<int> path2;

	if(findpath(root,path1,x) == false || findpath(root,path2,y) == false)
	{
		return -1;
	}

	int i;
	for(i=0;i < path1.size() && i < path2.size();i++)
	{
		if(path1[i] != path2[i])
		{
			break;
		}
	}

	return path1[i-1];
}

int main()
{
	node* btree = createBtree();
	int x,y;

	x = 3;y = 6;
	cout << "findLCA(" << x << "," << y << ") => " << findLCA(btree,x,y) << endl;

	x = 3;y = 9;
	cout << "findLCA(" << x << "," << y << ") => " << findLCA(btree,x,y) << endl;

	x = 9;y = 12;
	cout << "findLCA(" << x << "," << y << ") => " << findLCA(btree,x,y) << endl;

	return 0;
}
