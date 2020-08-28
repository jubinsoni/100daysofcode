# include <iostream>
#include <algorithm>

using namespace std;

int arr[1000][1000] = {0};

int rodCutting(int wt[],int val[],int n,int W)
{
	if(W == 0 || n == 0)
	{
		return 0;
	}

	if(arr[n][W] > 0)
	{
		return arr[n][W];
	}

	int lastIndex = n - 1;
	if(wt[lastIndex] > W)
	{
		arr[n][W] = rodCutting(wt,val,n-1,W-0);
		return arr[n][W];
	}
	else // if(wt[lastIndex] <= W)
	{
		arr[n][W] = max(val[lastIndex] + rodCutting(wt,val,n,W-wt[lastIndex]),rodCutting(wt,val,n-1,W-0));
		return arr[n][W];
	}
}


int main()
{
	int wt[] = {1,2,3,4,5,6,7,8};
	int val[] = {1,5,8,9,10,17,17,20};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 4;

	cout << "Most efficient way to cut rod of length = " << W << " is : " << rodCutting(wt,val,n,W) << endl;
	return 0;
}