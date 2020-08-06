#include <iostream>
#include <queue>
#include <stack>

using namespace std;


void reverseQueue(queue<int> &qu)
{
	stack<int> st;
	while(qu.empty() == false)
	{
		st.push(qu.front());
		qu.pop();
	}

	while(st.empty() == false)
	{
		qu.push(st.top());
		st.pop();
	}
}

void printQueue(queue<int> q)
{
	while(q.empty() == false)
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << "before reversing => ";
	printQueue(q);
	reverseQueue(q);
	cout << "after reversing => ";
	printQueue(q);

	return 0;
}