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
	newnode->next = NULL;
	newnode->data = arr[itr];
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

void createCycle(node** headptr)
{
	node* head = *headptr;
	node* last = *headptr;
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = head->next->next;
}

void CycleDetection(node** headptr)
{
	node* slow = *headptr;
	node* fast = *headptr;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			cout << "cycle detected" << endl;
			return;
		}
	}

	cout << "Linked list doesn't contains cycle" << endl;
}

int main()
{
	node* headptr = NULL;
	createList(&headptr);
	printList(&headptr);
	//--------------------
	createCycle(&headptr);
	//Don't uncomment below line becoz now linked list has a cycle...printing it will go in infinite loop
	//printList(&headptr);
	CycleDetection(&headptr);

	return 0;
}