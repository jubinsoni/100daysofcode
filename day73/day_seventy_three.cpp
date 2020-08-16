# include <iostream>

using namespace std;

int arr[1000][1000] = {0};
bool decision[1000][1000] = {false};

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

	int lastIndex = n-1;

	if(arr[lastIndex][W] != 0)
	{
		return decision[lastIndex][W];
	}

	// choices that can be made for an element
	if(wt[lastIndex] > W)
	{
		arr[lastIndex][W] = 1;
		decision[lastIndex][W] = isSubsetPossible(wt,n-1,W-0);

		return decision[lastIndex][W];
	}
	else // (wt[lastIndex] <= W)
	{
		arr[lastIndex][W] = 1;
		decision[lastIndex][W] = isSubsetPossible(wt,n-1,W-wt[lastIndex]) || isSubsetPossible(wt,n-1,W-0);

		return decision[lastIndex][W];
	}
}

int minimumSubsetDiff(int wt[],int n)
{
	int totalSum = 0;

	for(int i=0;i<n;i++)
	{
		totalSum = totalSum + wt[i];
	}

	int minWeight = INT_MAX;
	for(int weight=0;weight<=totalSum/2;weight++)
	{
		int temp = totalSum - 2*weight;
		if(isSubsetPossible(wt,n,weight) == true && minWeight > temp )
		{
			minWeight = temp;
		}
	}

	return minWeight;
}

int main()
{
	int wt1[] = {1,2,7};
	int n1 = sizeof(wt1)/sizeof(wt1[0]);

	cout << "minimumSubsetDiff of {1,2,7} => " << minimumSubsetDiff(wt1,n1) << endl;

	int wt2[] = {1,6,11,5};
	int n2 = sizeof(wt2)/sizeof(wt2[0]);

	cout << "minimumSubsetDiff of {1,6,11,5} => " << minimumSubsetDiff(wt2,n2) << endl;

	return 0;
}