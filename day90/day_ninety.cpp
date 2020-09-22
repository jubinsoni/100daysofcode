# include <bits/stdc++.h>

using namespace std;

int lengthLongestIncreasingSubsequence(int arr[],int n,int result[])
{
	result[0] = 1;

	for(int i=1;i<n;i++)
	{
		// initial base condition
		result[i] = 1;

		// subproblem solution computation
		for(int j=0;j<i;j++)
		{
			if(arr[i] >= arr[j] && result[i] < result[j] + 1)
			{
				result[i] = result[j] + 1;
			}
		}
	}

	int max_elem = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(result[i] > max_elem)
		{
			max_elem = result[i];
		}
	}

	return max_elem;

}

void printLongestIncreasingSubsequence(int arr[],int result[],int n)
{
	int max_ind = 0;
	int max_val = INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(max_val < result[i])
		{
			max_ind = i;
			max_val = result[i];
		}
	}

	vector<int> lis_vector;

	lis_vector.push_back(arr[max_ind]);

	for(int j=max_ind-1;j>=0;j--)
	{
		if(arr[j] < arr[max_ind] && result[j]+1 == result[max_ind])
		{
			max_ind = j;
			lis_vector.push_back(arr[j]);
		}
	}

	
	reverse(lis_vector.begin(),lis_vector.end());

	for(int i=0;i<lis_vector.size();i++)
	{
		cout << lis_vector[i] << " ";
	}
	cout << endl;

}

void printArr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {50,3,10,7,40,80};
	int n = sizeof(arr)/sizeof(arr[0]);

	int result[n];

	cout << "lengthLongestIncreasingSubsequence of sequence : ";
	printArr(arr,n);
	cout << "=> " << lengthLongestIncreasingSubsequence(arr,n,result) << endl;

	cout << "----------------" << endl;

	cout << "printingLongestIncreasingSubsequence of sequence : ";
	printArr(arr,n);
	cout << "=> ";
	printLongestIncreasingSubsequence(arr,result,n);
	cout << endl;

	return 0;
}