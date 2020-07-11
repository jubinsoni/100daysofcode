import java.util.Stack;

public class DayThirtyEight
{
	public static void main(String args[])
	{
		DayThirtyEight occurence = new DayThirtyEight();
		int arr[] = {2,3,3,3,3,3,3,3,8,8,8};
		int size = arr.length;
		int x = 3;
		System.out.print("Number of occurence of x = " + x + " => ");
		System.out.println(occurence.rightmostOccurence(arr,x,size,0,size-1) - occurence.leftmostOccurence(arr,x,size,0,size-1) + 1);
	}

	private int leftmostOccurence(int arr[],int x,int n,int left,int right)
	{
		if(left <= right)
		{
			int mid = left + right-left/2;
			if(arr[mid] == x && (arr[mid-1] < x || mid == 0))
			{
				return mid;
			}
			// recurse left as much as possible
			else if(x <= arr[mid])
			{
				return leftmostOccurence(arr,x,n,left,mid-1);
			}
			else if(x > arr[mid])
			{
				return leftmostOccurence(arr,x,n,mid+1,right);
			}
		}
		return -1;
	}

	private int rightmostOccurence(int arr[],int x,int n,int left,int right)
	{
		if(left <= right)
		{
			int mid = left + right-left/2;
			if(arr[mid] == x && (arr[mid+1] > x || mid == n-1))
			{
				return mid;
			}
			//recurse right as much as possible
			else if(x >= arr[mid])
			{
				return rightmostOccurence(arr,x,n,mid+1,right);
			}
			else if(x < arr[mid])
			{
				return rightmostOccurence(arr,x,n,left,mid-1);
			}
		}
		return -1;
	}
}