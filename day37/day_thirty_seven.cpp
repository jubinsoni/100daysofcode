# include <iostream>
# include <stack>

using namespace std;


void printStack(stack<int> st)
{
	while(st.empty() == false)
	{
		int temp = st.top();
		cout << temp << " ";
		st.pop();
	}
	cout << endl;
}

void leadersInArray(int arr[],int n)
{
	stack<int> st;
	int maxz = INT_MIN;
	for(int i=n-1;i>=0;i--)
	{
		if(maxz < arr[i])
		{
			maxz = arr[i];
			st.push(maxz);
		}
	}

	printStack(st);
}


int main()
{
	int arr[] = {5,3,20,15,8,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	leadersInArray(arr,size);

	return 0;
}