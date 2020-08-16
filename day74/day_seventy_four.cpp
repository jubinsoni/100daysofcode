# include <iostream>

using namespace std;


int countSubsetSumPosssible(int wt[],int n,int W)
{
	if(W < 0)
	{
		return 0;
	}

	if(n == 0 && W > 0 )
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
		return countSubsetSumPosssible(wt,n-1,W-0);
	}
	else //if(wt[lastIndex] <= W)
	{
		return countSubsetSumPosssible(wt,n-1,W-wt[lastIndex]) + countSubsetSumPosssible(wt,n-1,W-0);
	}
}

int countOfSubsetDiff(int wt[],int n,int diff)
{
	int totalSum = 0;
	for(int i=0;i<n;i++)
	{
		totalSum = totalSum + wt[i];
	}

	return countSubsetSumPosssible(wt,n,(totalSum-diff)/2);
}

int main()
{
	int wt1[] = {1,1,2,3};
	int diff = 1;
	int n1 = sizeof(wt1)/sizeof(wt1[0]);

	cout << "countOfSubsetDiff of {1,1,2,3} = 1 => " << countOfSubsetDiff(wt1,n1,diff) << endl;
	
	return 0;
}