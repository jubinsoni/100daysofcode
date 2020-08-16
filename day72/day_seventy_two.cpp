# include <iostream>

using namespace std;

int countSubsetSumPossible(int wt[],int W,int n)
{
	if(W < 0)
	{
		return 0;
	}

	if(n == 0 &&  W > 0)
	{
		return 0;
	}

	if(n == 0 &&  W == 0)
	{
		return 1;
	}

	int lastIndex = n-1;

	if(wt[lastIndex] > W)
	{
		return countSubsetSumPossible(wt,W-0,n-1);
	}
	else //if(wt[lastIndex] <= W)
	{
		return countSubsetSumPossible(wt,W-wt[lastIndex],n-1) + countSubsetSumPossible(wt,W-0,n-1);
	}
}

int main()
{
	int wt[] = {2,3,5,6,8,10};
	int W = 10;
	int n = sizeof(wt)/sizeof(wt[0]);

	cout << "countSubsetSumPossible => " << countSubsetSumPossible(wt,W,n) << endl;

	return 0;
}