# include <bits/stdc++.h>

using namespace std;

int mcm(int arr[],int i,int j)
{
	if(i >= j)
	{
		return 0;
	}

	int min_cost = INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);

		min_cost = min(temp,min_cost);
	}

	return min_cost;
}

int mem_tab[100][100] = {0};

int mcmMemoization(int arr[],int i,int j)
{
	if(i >= j)
	{
		return 0;
	}

	if(mem_tab[i][j] > 0)
	{
		return mem_tab[i][j];
	}

	int min_cost = INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);

		min_cost = min(temp,min_cost);
	}

	mem_tab[i][j] = min_cost;

	return mem_tab[i][j];
}


void printArr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{

	//int arr[] = {40,20,30,10,30};

	int arr[] = {10,30,5,60};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Minimum Cost Of Matrix Chain Multiplication of ";
	printArr(arr,n);
	cout << " => " << mcm(arr,1,n-1) << endl;

	cout << "--------" << endl;

	cout << "Minimum Cost Of Matrix Chain Multiplication of(Memoization) ";
	printArr(arr,n);
	cout << " => " << mcmMemoization(arr,1,n-1) << endl;

	return 0;
}