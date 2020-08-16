# include <iostream>

using namespace std;

int arr[1000][1000] = {-1};

int unboundedKnapsack(int wt[],int val[],int n,int W)
{
	if(n == 0 || W == 0)
	{
		return 0;
	}

	// memoization
	if(arr[n][W] > 0)
	{
		return arr[n][W];
	}

	//coding choice diagram
	int lastIndex = n-1;
	if(wt[lastIndex] > W)
	{
		arr[n][W] = unboundedKnapsack(wt,val,n-1,W-0);
		return arr[n][W];
	}
	else //if(wt[lastIndex] <= W)
	{
		arr[n][W] =  max(val[lastIndex] + unboundedKnapsack(wt,val,n,W-wt[lastIndex]),unboundedKnapsack(wt,val,n-1,W-0));
		return arr[n][W];
	}
}

int main()
{
	int wt[] = {1, 3, 4, 5};
	int val[] = {10, 40, 50, 70};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 8;

	cout << "Max Value for unboundedKnapsack of {1,3,4,5} => " << unboundedKnapsack(wt,val,n,W) << endl;
  
	return 0;
}