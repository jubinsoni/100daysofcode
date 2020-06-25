# include <iostream>

using namespace std;

void printArray(int arr[],int n)
{
	for(int i=0;i<=n-1;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int* x,int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp; 
}

// swap adjacent element for n2 if(arr[j > arr[j+1]])
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<=n-2;i++)
	{
		for(int j=0;j<=n-2;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

// find minimum in n and repalce for i in n
void selectionSort(int arr[],int n)
{
	for(int i=0;i<=n-1;i++)
	{
		int minIndz = i;
		for(int j=i+1;j<=n-1;j++)
		{
			if(arr[minIndz] > arr[j])
			{
				minIndz = j;
			}
		}
		swap(&arr[i],&arr[minIndz]);
	}
}

int main()
{
	int arr1[] = {7,5,14,12,11,9,4,3,1,54};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	bubbleSort(arr1,n1);
	printArray(arr1,n1);

	int arr2[] = {7,5,14,12,11,9,4,3,1,54};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	selectionSort(arr2,n2);
	printArray(arr2,n2);

	return 0;
}