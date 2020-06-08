# include <iostream>

using namespace std;

typedef struct Node
{
	struct Node* next;
	int data;
}node;

int itr = 0;
int arr[] = {87,99,23,4,11,234,78,90,34,67,76};
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

void insertHead(node** headptr,int val)
{
	node* head = *headptr;
	node* newnode = getNode();
	newnode->data = val;
	newnode->next = head;
	head = newnode;
	*headptr = head;
}

void insertLast(node** headptr,int val)
{
	node* last = *headptr;
	while(last->next != NULL)
	{
		last = last->next;
	}
	node* newnode = getNode();
	newnode->data = val;
	newnode->next = NULL;
	last->next = newnode;
	last = last->next;
}

void insertMiddle(node** headptr,int val)
{
	node* slow = *headptr;
	node* fast = *headptr;
	while(fast->next != NULL && fast != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	node* newnode = getNode();
	newnode->data = val;
	newnode->next = slow->next;
	slow->next = newnode;
}

void printList(node** headptr)
{
	node* temp = *headptr;
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
	printList(&headptr);
	cout << "-----------" << endl;
	cout << "insertHead,23 => " << endl;
	insertHead(&headptr,23);
	printList(&headptr);
	cout << "-----------" << endl;
	cout << "insertLast,32 => " << endl;
	insertLast(&headptr,32);
	printList(&headptr);
	cout << "-----------" << endl;
	cout << "insertMiddle,55 => " << endl;
	insertMiddle(&headptr,55);
	printList(&headptr);

	return 0;
}