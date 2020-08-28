# include <iostream>

using namespace std;

int minCoinsCoinChange(int wt[],int n,int W)
{
	if(n == 0)
	{
		return INT_MAX - 1 ;
	}

	if(W == 0 && n > 0)
	{
		return 0;
	}


	if(n == 1 && W > 0)
	{
		if(W % wt[0] == 0)
		{
			return W/wt[0];
		}
		else
		{
			return INT_MAX - 1 ;
		}
	}

	int lastIndex = n-1;

	if(wt[lastIndex] > W)
	{
		return 0 + minCoinsCoinChange(wt,n-1,W-0);
	}
	else // if(wt[lastIndex] <= W)
	{
		return min(1 + minCoinsCoinChange(wt,n,W-wt[lastIndex]) , 0 + minCoinsCoinChange(wt,n-1,W-0));
	}	
}


int arr[10][10];

int minCoinsCoinChangeMemoization(int wt[],int n,int W)
{
	if(n == 0)
	{
		return INT_MAX - 1 ;
	}

	if(W == 0 && n > 0)
	{
		return 0;
	}


	if(n == 1 && W > 0)
	{
		if(W % wt[0] == 0)
		{
			return W/wt[0];
		}
		else
		{
			return INT_MAX - 1 ;
		}
	}
	
	if(arr[n][W] != INT_MAX)
	{
		return arr[n][W];
	}

	int lastIndex = n-1;

	if(wt[lastIndex] > W)
	{
		arr[n][W] = 0 + minCoinsCoinChangeMemoization(wt,n-1,W-0);
		return arr[n][W];
	}
	else // if(wt[lastIndex] <= W)
	{
		arr[n][W] = min(1 + minCoinsCoinChangeMemoization(wt,n,W-wt[lastIndex]) , 0 + minCoinsCoinChangeMemoization(wt,n-1,W-0));
		return arr[n][W];
	}	
}

int main()
{
	int wt[] = {1,2,3};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 5;

	// initialzing array
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j] = INT_MAX;
		}
	}

	cout << "Min coins to get a particular sum(recursive) = " << minCoinsCoinChange(wt,n,W) << endl;
	cout << "Min coins to get a particular sum(recursive + memoization) = " << minCoinsCoinChangeMemoization(wt,n,W) << endl;

	return 0;
}