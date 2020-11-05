# include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;		
}node;

node* getNode()
{
	node* newnode = (node*)malloc(sizeof(node));
	return newnode;
}

void readNode(node* newnode,int n)
{
	newnode->data = n;
	newnode->next = NULL;
}

void createList(node** head)
{
	node* last = *head;
	node* headptr = *head;
	
	for(int i=0;i<=5;i++)
	{
		node* newnode = getNode();
		readNode(newnode,i*10);
		if(last == NULL)
		{
			last = newnode;
			headptr = newnode;
		}
		else
		{
			last->next = newnode;
			last = last->next;
		}
	}
	*head = headptr;
}

void printList(node** head)
{
	node* last = *head;
	while(last != NULL)
	{
		cout << last->data << " ";
		last = last->next;
	}
	cout << endl;
}

void addHead(node** head,int n)
{
	node* last = *head;
	node* newnode = getNode();
	readNode(newnode,n);
	newnode->next = last;
	last = newnode;

	*head = last;
}

void addTail(node** head,int n)
{
	node* last = *head;
	while(last->next != NULL)
	{
		last = last->next;
	}

	node* newnode = getNode();
	readNode(newnode,n);

	last->next = newnode;
}

void removeHead(node** head)
{
	node* last = *head;
	node* headptr = *head;
	headptr = headptr->next;
	last->next = NULL;
	*head = headptr;
}

void removeTail(node** head)
{
	node* last = *head;
	node* prev = *head;
	while(last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
}

int getMiddle(node** head)
{
	node* slow = *head;
	node* fast = *head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

void createLoop(node** head)
{
	node* last = *head;
	node* headptr = *head;

	while(last->next != NULL)
	{
		last = last->next;
	}

	last->next = headptr->next->next;
}

void removeLoop(node** head)
{
	node* slow = *head;
	node* fast = *head;
	node* headptr = *head;

	while(1 == 1)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow)
		{
			break;
		}
	}

	fast = *head;

	while(fast->next != slow->next)
	{
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = NULL;
}

void reverseList(node** head)
{
	node* prev = NULL;
	node* curr = *head;
	node* nextptr;

	while(curr != NULL)
	{
		nextptr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextptr;
	}

	*head = prev;
}

int main()
{
	node* head = NULL;
	createList(&head);
	printList(&head);
	cout << "----" << endl; 
	addHead(&head,90);
	addTail(&head,100);
	printList(&head);
	cout << "----" << endl;
	removeHead(&head);
	removeTail(&head);
	printList(&head);
	cout << "----" << endl;
	cout << "getMiddle => " << getMiddle(&head) << endl;
	cout << "----" << endl;
	createLoop(&head);
	removeLoop(&head);
	printList(&head);
	cout << "----" << endl;
	reverseList(&head);
	printList(&head);

	return 0;
}