# include <iostream>

using namespace std;

int knapSack(int W,int wt[],int val[],int n)
{
	if(n==0 || W == 0)
	{
		return 0;
	}

	int lastIndex = n-1; //as n-1 is last element

	if(wt[lastIndex] > W)
	{
		return 0 +  knapSack(W-0,wt,val,n-1);
	}
	else //if(wt[lastIndex] <= W)
	{
		return max(val[lastIndex] + knapSack(W-wt[lastIndex],wt,val,n-1), 0 + knapSack(W-0,wt,val,n-1));
	}
}

int arr[1000][1000] = {-1};

int knapSackMemoization(int W,int wt[],int val[],int n)
{
	if(n==0 || W == 0)
	{
		return 0;
	}

	int lastIndex = n-1; //as n-1 is last element
	if(arr[lastIndex][W] > 0)
	{
		return arr[lastIndex][W];
	}

	if(wt[lastIndex] > W)
	{
		arr[lastIndex][W] = 0 +  knapSackMemoization(W-0,wt,val,n-1);
		return arr[lastIndex][W];
	}
	else //if(wt[lastIndex] <= W)
	{
		arr[lastIndex][W] = max(val[lastIndex] + knapSackMemoization(W-wt[lastIndex],wt,val,n-1), 0 + knapSackMemoization(W-0,wt,val,n-1));
		return arr[lastIndex][W];
	}
}

// add knapsack without memoization

int main()
{
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 

    cout << "knapSack => " << knapSack(W, wt, val, n) << endl;
    cout << "knapSackMemoization => " << knapSackMemoization(W, wt, val, n) << endl;

	return 0;
}