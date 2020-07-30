# include <iostream>
# include <stack>

using namespace std;

void prevGreater(int arr[],int n)
{
	stack<int> st;
	st.push(arr[0]);
	cout << "_";
	for(int i=1;i<n;i++)
	{
		while(st.empty() == false && st.top() < arr[i])
		{
			st.pop();
		}

		if(st.empty() == true)
		{
			cout << "_" << " "; 
		}
		else
		{
			cout << st.top() << " "; 
		}
		st.push(arr[i]);
	}
	cout << endl;
}

void previousSmaller(int arr[],int n)
{
	stack<int> st;
	st.push(arr[0]);
	cout << "_";
	for(int i=1;i<n;i++)
	{
		while(st.empty() == false && st.top() > arr[i])
		{
			st.pop();
		}

		if(st.empty() == true)
		{
			cout << "_" << " "; 
		}
		else
		{
			cout << st.top() << " "; 
		}
		st.push(arr[i]);
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
	int arr2[] = {10, 4, 2, 20, 40, 12, 30};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	printArr(arr2, n2);
	prevGreater(arr2,n2);
	
	cout << "--------" << endl;

	int arr1[] = {1,3,0,2,5};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	printArr(arr1, n1);
	previousSmaller(arr1,n1);

	return 0;
}