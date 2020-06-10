# include <iostream>

using namespace std;

// O(logn)
void heapifyMin(int arr[],int n,int i)
{
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] < arr[smallest])
	{
		smallest = l;
	}

	if(r < n && arr[r] < arr[smallest])
	{
		smallest = r;
	}

	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);
		heapifyMin(arr,n,smallest);
	}
}

// O(nlogn)
void heapSortMin(int arr[],int n)
{
	// build heap O(n) 
	// last internal node => n/2 - 1
	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMin(arr,n,i);
	}

	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapifyMin(arr,i,0);
	}

	// printing sorted array
	// since minimum element will be at the end
	for(int i=n-1;i>=0;i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = {4,6,3,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	heapSortMin(arr,n);

	return 0;
}