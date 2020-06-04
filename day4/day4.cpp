# include <iostream>

using namespace std;

typedef struct Node
{
	struct Node* next;
	struct Node* prev;
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
	itr = itr + 1;
	newnode->next = NULL;
	newnode->prev = NULL;
}


void createList(node** headptr)
{
	node* head = *headptr;
	node*last = *headptr;
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
			newnode->prev = last;
			last = last->next;
		}
	}
	*headptr = head;
}


void printList(node** headptr)
{
	node* temp = *headptr;
	cout << "printing list from start till end => ";

	while(temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " "; 
	cout << endl;

	cout << "printing list from last to first => ";

	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main()
{
	node* headptr = NULL;
	createList(&headptr);
	printList(&headptr);
	return 0;
}