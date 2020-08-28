# include <iostream>
#include <algorithm>

using namespace std;

int arr[1000][1000] = {0};

int maxWayCoinChange(int wt[],int n,int W)
{
	if(W < 0)
	{
		return 0;
	}

	if(n == 0 && W > 0)
	{
		return 0;
	}

	if(n == 0 && W == 0)
	{
		return 1;
	}

	int lastIndex = n-1;

	if(wt[lastIndex] > W)
	{
		arr[n][W] = maxWayCoinChange(wt,n-1,W-0);
		return arr[n][W];
	}
	else // if(wt[lastIndex] <= W)
	{
		arr[n][W] = maxWayCoinChange(wt,n,W-wt[lastIndex]) + maxWayCoinChange(wt,n-1,W-0);
		return arr[n][W];
	}

}


int main()
{
	int wt[] = {1,2,3};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 5;

	cout << "Max ways to get a particular sum = " << maxWayCoinChange(wt,n,W) << endl;
	return 0;
}