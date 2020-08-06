# include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Queue
{
	Node* head;
public:
	Queue()
	{
		head = NULL;
	}

	void add(int x);
	int front();
	void remove();
	void createQueue();
	bool isEmpty();
	void removeAllAndPrint(class Queue &q);
};

void Queue::add(int x)
{
	Node* newnode = new Node();
	newnode->data = x;
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

void Queue::createQueue()
{
	for(int i=1;i<6;i++)
	{
		add(i*10);
	}
}

int Queue::front()
{
	if(head == NULL)
	{
		return -1;
	}

	return head->data;
}

void Queue::remove()
{
	if(head == NULL)
	{
		cout << "queue is already empty...nothing to remove" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
	}
}

bool Queue::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}

	return false;
}

void Queue::removeAllAndPrint(class Queue &q)
{
	while(q.isEmpty() == false)
	{
		cout << q.front() << " ";
		q.remove();
	}
	cout << endl;
}

int main()
{
	class Queue q;
	q.createQueue();
	q.removeAllAndPrint(q);

	return 0;
}