public class DayFifteen
{
	public static void main(String args[])
	{
		int arr[] = {1,5,-7,-8,10,11,9,-20,11};
		DayFifteen maxSubArraySum = new DayFifteen();
		System.out.println(maxSubArraySum.kadane(arr));
	}

	public int kadane(int arr[])
	{
		int max_sum_curr = 0;
		int max_sum_till_now = 0;

		for(int i=0;i<arr.length;i++)
		{
			max_sum_curr = max_sum_curr + arr[i];
			if(max_sum_curr < 0)
			{
				max_sum_curr = 0;
			}
			else if(max_sum_till_now < max_sum_curr)
			{
				max_sum_till_now = max_sum_curr;
			}
		}

		return max_sum_till_now;
	}
}