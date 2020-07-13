# include <iostream>

using namespace std;

int binarySearch(int arr[],int left,int right,int x)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;
		if(x == arr[mid])
		{
			return mid;
		}
		else if(x < arr[mid])
		{
			return binarySearch(arr,left,mid-1,x);
		}
		else if(x > arr[mid])
		{
			return binarySearch(arr,mid+1,right,x);
		}
	}
	return -1;
}


int findInInfArr(int arr[],int size,int x)
{
	if(arr[0] == x)
	{
		return 0;
	}

	int i = 1;
	while(i < size && x > arr[i])
	{
		i = i*2;
	}

	if(arr[i] == x)
	{
		return i;
	}
	return binarySearch(arr,i/2,i,x);
}

int main()
{
	int arr[] = {10,20,25,50,70,80};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 50;
	cout << "Element found at Index => " << findInInfArr(arr,size,x) << endl;

	return 0;
}