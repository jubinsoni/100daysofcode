# include <iostream>

using namespace std;

bool isSubsetSumPossible(int wt[],int W,int n)
{
	if(W < 0)
	{
		return false;
	}

	if(n == 0 && W > 0)
	{
		return false;
	}

	if(n == 0 && W == 0)
	{
		return true;
	}

	int lastIndex = n-1;

	if(wt[lastIndex] > W)
	{
		return isSubsetSumPossible(wt,W-0,n-1);
	}
	else // if(wt[lastIndex] <= W)
	{
		return isSubsetSumPossible(wt,W-wt[lastIndex],n-1) || isSubsetSumPossible(wt,W-0,n-1);
	}

}

int arr[1000][1000] = {0};
bool decision[1000][1000] = {false};

bool isSubsetSumPossibleMemoization(int wt[],int W,int n)
{
	if(W < 0)
	{
		return false;
	}

	if(n == 0 && W > 0)
	{
		return false;
	}

	if(n == 0 && W == 0)
	{
		return true;
	}

	int lastIndex = n-1;

	if(arr[lastIndex][W] > 0)
	{
		return decision[lastIndex][W];
	}

	if(wt[lastIndex] > W)
	{
		arr[lastIndex][W] = 1;
		decision[lastIndex][W] = isSubsetSumPossibleMemoization(wt,W-0,n-1);
		return decision[lastIndex][W];
	}
	else // if(wt[lastIndex] <= W)
	{
		arr[lastIndex][W] = 1;
		decision[lastIndex][W] = isSubsetSumPossibleMemoization(wt,W-wt[lastIndex],n-1) || isSubsetSumPossibleMemoization(wt,W-0,n-1);
		return decision[lastIndex][W];
	}

}

int main()
{
	int wt[] = {3,34,4,12,5,2};
	int W = 9;
	int n = sizeof(wt)/sizeof(wt[0]);

	cout << "isSubsetSumPossible => " << isSubsetSumPossible(wt,W,n) << endl;
	cout << "isSubsetSumPossibleMemoization => " << isSubsetSumPossibleMemoization(wt,W,n) << endl;

	return 0;
}