# include <iostream>
# include <stack>

using namespace std;

// No of contiguous days previous to current day 
// where stock value is less or equal to that current day

void stockSpan(int stock[],int n)
{
	stack<int> st;
	int s[n];


	st.push(0); // index gets inserted in stack
	s[0] = 1;	// actual value of days gets stored in array
	for(int i=1;i<n;i++)
	{
		while(st.empty() == false && stock[i] >= stock[st.top()])
		{
			st.pop();
		}

		if(st.empty() == true)
		{
			s[i] = i + 1;
		}
		else
		{
			s[i] = i - st.top();
		}

		st.push(i);
	}

	for(int i=0;i<n;i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void printArr(int arr[],int n)
{
	cout << "input Array => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int stock[] = {10,5,2,7,18,15,16,17};
	int n = sizeof(stock)/sizeof(stock[0]);

	printArr(stock,n);
	stockSpan(stock,n);

	return 0;
}