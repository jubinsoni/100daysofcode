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
	void printAllAndPop(class Stack &s);
	void reverseStack();
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

void Stack::pop()
{
	if(head == NULL)
	{
		cout << "Stack empty...pop() not possible" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
	}
}

bool Stack::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	return false;
}

void Stack::printAllAndPop(class Stack &s)
{
	cout << "poping all elements from stack => " ;
	while(s.isEmpty() == false)
	{
		cout << s.peek() << " ";
		s.pop();
	}
	cout << endl;
}

void Stack::reverseStack()
{
	Node* curr = head;
	Node* forward = head;
	Node* backward = NULL;

	while(curr != NULL)
	{
		forward = curr->next;
		curr->next = backward;
		backward = curr;
		curr = forward;
	}
	head = backward;
}

int main()
{
	class Stack s;

	cout << "pushing 10,20,30.....70" << endl;
	for(int i=1;i<8;i++)
	{
		s.push(i*10);
	}

	
	s.printAllAndPop(s);

	cout << "pushing 10,20,30.....70" << endl;
	for(int i=1;i<8;i++)
	{
		s.push(i*10);
	}

	s.reverseStack();

	s.printAllAndPop(s);
	
	return 0;
}