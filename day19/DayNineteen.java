import java.util.*;

public class DayNineteen
{
	public static void main(String args[])
	{
		DayNineteen subArrSum = new DayNineteen();
		int arr[] = {1,6,7,8,20,100};
		int x;
		x = 12;
		System.out.println("x = " + x + "," + subArrSum.arrayContainsPairSum(arr,arr.length,x));
		x = 15;
		System.out.println("x = " + x + "," + subArrSum.arrayContainsPairSum(arr,arr.length,x));
	}

	private String arrayContainsPairSum(int arr[],int n,int x)
	{
		Set<Integer> hset = new HashSet<Integer>();
		for(int i=0;i<n;i++)
		{
			if(hset.contains(x-arr[i]) == false)
			{
				hset.add(arr[i]);
			}
			else
			{
				return "arrayContainsPairSum";
			}
		}
		return "Doesn't contains PairSum";
	}

}