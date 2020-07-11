# include <iostream>

using namespace std;

int leftmostOccurence(int arr[],int x,int size,int left,int right)
{
	if(left <= right)
	{
		int mid = left + right-left/2;
		if(arr[mid] == x && (arr[mid-1] < x || mid == 0))
		{
			return mid;
		}
		// we want to recurse first left side as much as possible
		else if(x <= arr[mid])
		{
			return leftmostOccurence(arr,x,size,left,mid-1);
		}
		else if(x > arr[mid])
		{
			return leftmostOccurence(arr,x,size,mid+1,right);
		}
		
	}
	return -1;
}

int rightmostOccurence(int arr[],int x,int size,int left,int right)
{
	if(left <= right)
	{
		int mid = left + right-left/2;
		if(arr[mid] == x && (arr[mid+1] > x || mid == size-1))
		{
			return mid;
		}
		// we want to recurse first right side as much as possible
		else if(x >= arr[mid])
		{
			return rightmostOccurence(arr,x,size,mid+1,right);
		}
		else if(x < arr[mid])
		{
			return rightmostOccurence(arr,x,size,left,mid-1);
		}
	}
	return -1;
}

int main()
{
	int arr[] = {2,3,3,3,3,3,3,3,8,8,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 3;
	cout << "Number of occurence of x = " << x << " => ";
	cout << rightmostOccurence(arr,x,size,0,size-1) - leftmostOccurence(arr,x,size,0,size-1) + 1 << endl;

	return 0;
}