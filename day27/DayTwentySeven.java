import java.util.*;

public class DayTwentySeven
{
	public static void main(String args[])
	{
		int L[] = {1,2,5,15};
		int R[] = {5,8,7,18};
		int n = L.length;

		DayTwentySeven maxApp = new DayTwentySeven();
		System.out.println(maxApp.maxAppear(L,R,n));
	}

	private int maxAppear(int L[],int R[],int n)
	{
		int arr[] = new int [1000];
		for(int i=0;i<n;i++)
		{
			arr[L[i]] = arr[L[i]] + 1;
			arr[R[i] + 1] = arr[R[i] + 1] - 1;
		}

		int maxm = arr[0];
		int res = 0;

		for(int i=1;i<arr.length;i++)
		{
			arr[i] = arr[i] + arr[i-1];
			if(maxm < arr[i])
			{
				maxm = arr[i];
				res = i;
			}
		}
		return res;
	}
}