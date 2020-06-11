# include <iostream>

using namespace std;

// O(logn)
void heapifyMax(int arr[],int n,int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest])
	{
		largest = l;
	}

	if(r < n && arr[r] > arr[largest])
	{
		largest = r;
	}

	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapifyMax(arr,n,largest);
	}
}

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
	cout << "input array => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

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

// O(nlogn)
void heapSortMax(int arr[],int n)
{
	cout << "input array => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// build heap O(n) 
	// last internal node => n/2 - 1
	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMax(arr,n,i);
	}

	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapifyMax(arr,i,0);
	}

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// O(logn)
void insertKey(int arr[],int n,int key)
{
	cout << "input array => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// build heap O(n) 
	// last internal node => n/2 - 1
	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMax(arr,n,i);
	}

	cout << "max heap => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	n = n + 1;

	arr[n-1] = key;

	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMax(arr,n,i);
	}

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// O(logn)
void deleteRoot(int arr[],int n)
{
	cout << "input array => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// build heap O(n) 
	// last internal node => n/2 - 1
	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMax(arr,n,i);
	}

	cout << "max heap => ";
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int lastElement = arr[n - 1]; 
  
    arr[0] = lastElement; 
  
    n = n - 1; 
  
    heapifyMax(arr, n, 0);

    for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// O(1) if heap is already created
void getMin(int arr[],int n)
{
	// build heap O(n) 
	// last internal node => n/2 - 1
	for(int i=n/2-1;i>=0;i--)
	{
		heapifyMin(arr,n,i);
	}

	cout << "min => " << arr[0] << endl;
}

int main()
{
	int arr1[] = {4,6,3,9};
	int arr2[] = {4,6,3,9};
	int arr3[] = {4,6,3,9};
	int arr4[] = {4,6,3,9};
	int arr5[] = {4,6,3,9};
	int n = sizeof(arr1)/sizeof(arr1[0]);

	cout << "heapSortMin() " << endl;
	heapSortMin(arr1,n);
	cout << "heapSortMax() " << endl;
	heapSortMax(arr2,n);
	cout << "insertKey() " << endl;
	insertKey(arr3,n,15);
	cout << "deleteRoot() " << endl;
	deleteRoot(arr4,n);
	cout << "getMin() " << endl;
	getMin(arr5,n);

	return 0;
}