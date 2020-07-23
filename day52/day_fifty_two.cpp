# include <iostream>

using namespace std;

# define SIZE 100

class Stack
{
	int top;
public:
	//var
	int arr[SIZE];

	//constructor
	Stack()
	{
		top = -1;
	}

	// member function
	void push(int x);
	void pop();
	int peek();
	bool isEmpty();
};

void Stack::push(int x)
{
	top = top + 1;
	arr[top] = x;
}

void Stack::pop()
{
	top = top - 1;
}

int Stack::peek()
{
	return arr[top];
}

bool Stack::isEmpty()
{
	if(top <= -1)
	{
		return true;
	}

	return false;
}

int main()
{
	class Stack st;
	st.push(2);
	st.push(3);
	st.push(5);
	st.push(6);

	cout << "top element till now => " << st.peek() << endl;

	cout << "printing stack => ";
	while(st.isEmpty() == false)
	{
		cout << st.peek() << " ";
		st.pop();
	}
	cout << endl;

	return 0;
}