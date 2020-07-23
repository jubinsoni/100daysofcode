# include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList{
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}

	void addNode(int val);
	void createList();
	void printList();
};

void LinkedList::addNode(int val)
{
	Node* newnode = new Node();
	newnode->data = val;
	newnode->next = NULL;

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		Node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void LinkedList::createList()
{
	for(int i=0;i<5;i++)
	{
		addNode(i*10);
	}
}

void LinkedList::printList()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	class LinkedList list;
	list.createList();
	list.printList();
	return 0;
}