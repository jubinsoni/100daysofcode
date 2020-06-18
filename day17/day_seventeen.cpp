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

void getMiddle(node** headptr)
{
	node* slow = *headptr;
	node* fast = *headptr;
	while(fast->next != NULL && fast != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << slow->data << endl;
}

void printList(node* temp)
{
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	node* headptr = NULL;
	createList(&headptr);
	printList(headptr);
	cout << "--------------" << endl;
	getMiddle(&headptr);
	cout << "--------------" << endl;
	return 0;
}