import java.util.*;

public class DayTwenty
{
	public static void main(String args[])
	{
		DayTwenty subArrSum = new DayTwenty();
		int arr[] = {1,6,7,8,20,100};
		int x;
		x = 35;
		System.out.println("x = " + x + "," + subArrSum.subArrayContainsSum(arr,arr.length,x));
		x = 18;
		System.out.println("x = " + x + "," + subArrSum.subArrayContainsSum(arr,arr.length,x));
	}

	private String subArrayContainsSum(int arr[],int n,int x)
	{
		Set<Integer> hset = new HashSet<Integer>();
		int prefix_sum = 0;
		for(int i=0;i<n;i++)
		{
			prefix_sum = prefix_sum + arr[i];
			if(hset.contains(prefix_sum - x) == false)
			{
				hset.add(prefix_sum);
			}
			else
			{
				return "subArrayContainsSum";
			}
		}
		return "subArray Doesn't ContainsSum";
	}
}