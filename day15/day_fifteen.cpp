# include <iostream>

using namespace std;

int kadane(int arr[],int n)
{
	int max_sum_till_here = 0;
	int max_sum_now = 0;
	for(int i=0;i<n;i++)
	{
		max_sum_now = max_sum_now + arr[i];

		if(max_sum_now < 0)
		{
			max_sum_now = 0;
		}
		else if(max_sum_till_here < max_sum_now)
		{
			max_sum_till_here = max_sum_now;
		}
	}

	return max_sum_till_here;
}

int main()
{
	int arr[] = {1,5,-7,-8,10,11,9,-20,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << kadane(arr,n) << endl;
	return 0;
}