# include <bits/stdc++.h>

using namespace std;

void minJumps(int arr[],int n)
{
	for(int i=0;i<n;)
	{
		cout << arr[i] << "->";

		if(i + arr[i] > n)
		{
			cout << arr[n-1] << endl;
			return;
		}

		int tempInd = i;
		int temp = arr[i];
		for(int j=i+1;j<=i+arr[i];j++)
		{
			if(arr[j] > temp)
			{
				temp = arr[j];
				tempInd = j;
			}
		}

		if(i < n)
		{
			i = tempInd;
		}

	}
}

int main()
{
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	minJumps(arr,n);

	return 0;
}