# include <iostream>
# include <vector>

using namespace std;

int maxAppear(int L[],int R[],int n)
{
	vector<int> arr(1000,0);

	for(int i=0;i<n;i++)
	{
		arr[L[i]] = arr[L[i]] + 1;
		arr[R[i] + 1] = arr[R[i] + 1] - 1;
	}

	int maxm = arr[0];
	int res = 0;

	for(int i=1;i<arr.size();i++)
	{
		arr[i] = arr[i] + arr[i-1];
		if(maxm < arr[i])
		{
			maxm = arr[i];
			res = i;
		}
	}
	return res;
}

int main()
{
	int L[] = {1,2,5,15};
	int R[] = {5,8,7,18};
	int n = sizeof(L)/sizeof(L[0]);
	cout << maxAppear(L,R,n) << endl;
	return 0;
}