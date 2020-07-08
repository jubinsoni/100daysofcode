# include <iostream>

using namespace std;

//explaination => https://www.youtube.com/watch?v=MZaf_9IZCrc

void swap(int* x,int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// idea is to have all smaller element left of pivot
// and all larger element right of pivot
int partition(int arr[],int low,int high)
{
	int pivot = arr[high]; // last element

	int i = low - 1; // we start i with 1 less than first element
	// j starts from first element 
	// j runs till 1 less than last element as lastElement(high) is pivot
	for(int j=low;j<high;j++)
	{
		//compare each jth element with pivot
		if(arr[j] < pivot)
		{
			i = i + 1;
			swap(&arr[i],&arr[j]);
		}
	}

	// swapping pivot with (i+1)th element
	i = i + 1;
	swap(&arr[i],&arr[high]);
	return i;
}

void quickSort(int arr[],int low,int high)
{
	if(low < high)
	{
		int partitionIndex = partition(arr,low,high);
		quickSort(arr,low,partitionIndex-1);
		quickSort(arr,partitionIndex+1,high);
	}
}

int main()
{
	int arr[] = {80,10,90,60,30,20};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "before quickSort => " ;
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	quickSort(arr,0,n-1);

	cout << "after quickSort => " ;
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}