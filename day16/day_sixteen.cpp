# include <iostream>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;
}node;

int itr = 0;
int arr[] = {10,78,34,12,54,88,55};
int size = sizeof(arr)/sizeof(arr[0]);

node* getNode()
{
	node* newnode = (node*)malloc(sizeof(node));
	return newnode;
}

void readNode(node* newnode)
{
	newnode->data = arr[itr];
	newnode->next = NULL;
	itr = itr + 1;
}

void createList(node** headptr)
{
	node* head = *headptr;
	node* last = *headptr;
	for(int i=0;i<size;i++)
	{
		node* newnode = getNode();
		readNode(newnode);
		if(head == NULL)
		{
			head = newnode;
			last = head;
		}
		else
		{
			last->next = newnode;
			last = last->next;
		}
	}
	*headptr = head;
}

void reverseList(node** headptr)
{
	node* curr = *headptr;
	node* temp = *headptr;
	node* last = NULL;

	while(curr != NULL)
	{
		temp = curr->next;
		curr->next = last;
		last = curr;
		curr = temp;
	}
	*headptr = last;
}

void printList(node* newnode)
{
	while(newnode != NULL)
	{
		cout << newnode->data << " ";
		newnode = newnode->next;
	}
	cout << endl;
}

int main()
{
	node* headptr = NULL;
	createList(&headptr);
	printList(headptr);
	cout << "------------------" << endl;
	reverseList(&headptr);
	printList(headptr);
	cout << "------------------" << endl;
	return 0;
}