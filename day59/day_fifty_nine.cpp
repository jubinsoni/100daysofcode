# include <iostream>
# include <stack>

using namespace std;

void nextGreaterElement(int arr[],int n)
{
	stack<int> st;
	st.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		if(st.empty() == true)
		{
			st.push(arr[i]);
			continue;
		}

		while(st.empty() == false && st.top() < arr[i])
		{
			cout << st.top() << " -- " << arr[i] << endl;
			st.pop();
		}
		st.push(arr[i]);
	}

	while(st.empty() == false)
	{
		cout << st.top() << " -- " << -1 << endl;
		st.pop();
	}
}

void nextSmallerElement(int arr[],int n)
{
	stack<int> st;
	st.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		if(st.empty() == true)
		{
			st.push(arr[i]);
		}

		while(st.empty() == false && st.top() > arr[i])
		{
			cout << st.top() << " -- " << arr[i] << endl;
			st.pop();
		}
		st.push(arr[i]);
	}

	while(st.empty() == false)
	{
		cout << st.top() << " -- " << -1 << endl;
		st.pop();
	}
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
	int arr1[] = {5,10,7,8,3,2,12};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	printArr(arr1, n1);
	cout << "(element -- nextGreaterElement)" << endl;
	nextGreaterElement(arr1,n1);

	cout << "--------" << endl;

	int arr2[] = {4,8,5,2,25};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	printArr(arr2, n2);
	cout << "(element -- nextSmallerElement)" << endl;
	nextSmallerElement(arr2,n2);

	return 0;
}