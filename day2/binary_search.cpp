# include <iostream>

using namespace std;

void naiveSearch(int arr[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i] == key)
		{
			cout << "key found" << endl;
			break;
		}
	}

	if(i == n)
	{
		cout << "key not found" << endl;
	}
}

void binarySearch(int arr[],int key,int left,int right)
{
	if(left <= right)
	{
		int mid = left + (right-left)/2;
		if(arr[mid] == key)
		{
			cout << "key found" << endl;
			return;
		}
		else if(arr[mid] > key)
		{
			binarySearch(arr,key,left,mid-1);
		}
		else if(arr[mid] < key)
		{
			binarySearch(arr,key,mid+1,right);
		}
	}
	else
	{
		cout << "key not found" << endl;
	}
}

int main()
{
	int arr[] = {5,9,23,67,89,102,123,127,150,172,189};
	int key = 172;

	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "naiveSearch => ";
	naiveSearch(arr,size,key);
	cout << "binarySearch => ";
	binarySearch(arr,key,0,size-1);

	return 0;
}