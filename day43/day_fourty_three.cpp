# include <iostream>

using namespace std;

int searchSortedRotated(int arr[],int left,int right,int x)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;

		if(arr[mid] == x)
		{
			return mid;
		}

		// if from left till mid is sorted
		if(arr[left] <= arr[mid])
		{
			if(x >= arr[left] && x <= arr[mid])
			{
				return searchSortedRotated(arr,left,mid-1,x);
			}
			else
			{
				return searchSortedRotated(arr,mid+1,right,x);
			}
		}
		// if from left till mid is not sorted then
		// from right till end is sorted
		else 
		{
			if(x >= arr[mid] && x <= arr[right])
			{
				return searchSortedRotated(arr,mid+1,right,x);
			}
			else
			{
				return searchSortedRotated(arr,left,mid-1,x);
			}
		}
	}
	return -1;
}

int main()
{
	int arr[] = {10,20,40,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 20;
	cout << "Index of Found element is => " << searchSortedRotated(arr,0,size-1,x) << endl;
	return 0;
}