# include <iostream>

using namespace std;

# define MAX 1000

class Queue
{
	int size;
	int front;
public:
	int arr[MAX];
	Queue()
	{
		size = 0;
		front = -1;
	}

	void add(int x);
	int peek();
	void remove();
	bool isEmpty();
	void createQueue();
	void printQueue(class Queue &q);
};

void Queue::add(int x)
{
	if(size == 0)
	{
		front = 0;
	}
	size = size + 1;
	arr[size-1] = x;
}

int Queue::peek()
{
	if(size == 0)
	{
		cout << "queue empty " << endl;
	}
	return arr[front];
}

void Queue::remove()
{
	if(front < size)
	{
		front = front + 1;
	}
	else
	{
		cout << "queue full" << endl;
	}

}

bool Queue::isEmpty()
{
	if(front == size)
	{
		return true;
	}
	return false;
}

void Queue::createQueue()
{
	for(int i=1;i<6;i++)
	{
		add(i*10);
	}
}

void Queue::printQueue(class Queue &q)
{
	while(q.isEmpty() == false)
	{
		cout << q.peek() << " ";
		q.remove();
	}
	cout << endl;
}

int main()
{
	class Queue q;
	q.createQueue();
	q.printQueue(q);

	return 0;
}

