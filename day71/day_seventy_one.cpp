# include <iostream>

using namespace std;


bool isSubsetPossible(int wt[],int n,int W)
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

	// coding choice diagram

	int lastIndex = n-1;
	if(wt[lastIndex] > W)
	{
		return isSubsetPossible(wt,n-1,W-0);
	}
	else // if(wt[lastIndex] <= W)
	{
		return isSubsetPossible(wt,n-1,W-wt[lastIndex]) || isSubsetPossible(wt,n-1,W-0);; 
	}
}

bool equalSumPartition(int wt[],int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum = sum + wt[i];
	}

	if(sum%2 == 1)
	{
		return false;
	}
	else //if(sum%2 == 0)
	{
		return isSubsetPossible(wt,n,sum/2);
	}
}

int main()
{
	int wt[] = {1,5,11,5};
	int n = sizeof(wt)/sizeof(wt[0]);

	cout << "equalSumPartition => " << equalSumPartition(wt,n) << endl;
	return 0;
}