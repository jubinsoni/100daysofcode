# include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Stack
{
	Node* head;
public:
	Stack()
	{
		head = NULL;
	}
	void push(int val);
	int peek();
	void pop();
	bool isEmpty();
	void popAllAndPrint(class Stack &list);
};

void Stack::push(int val)
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
		newnode->next = head;
		head = newnode;
	}
}

int Stack::peek()
{
	if(head == NULL)
	{
		return -1;
	}
	return head->data;
}

bool Stack::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	return false;
}

void Stack::pop()
{
	if(head == NULL)
	{
		cout << "Stack Empty...pop() cannot be done" << endl;
	}
	Node* temp = head;
	head = head->next;
	temp->next = NULL;
}

void Stack::popAllAndPrint(class Stack &list)
{
	while(list.isEmpty() == false)
	{
		cout << list.peek() << " ";
		list.pop();
	}
	cout << endl;
}

int main()
{
	class Stack list;

	cout << "pushing 10,20,30...80 to stack " << endl;;
	for(int i=1;i<9;i++)
	{
		list.push(i*10);
	}

	cout << "peek...expected (80) => " << list.peek() << endl;

	list.pop();

	cout << "after pop() doing peek...expected (70) => " << list.peek() << endl;

	cout << "poping and printing remaing elements in the stack => ";
	list.popAllAndPrint(list);

	return 0;
}