# include <bits/stdc++.h>

using namespace std;

int kthLargest(int arr1[],int n,int x)
{
	priority_queue <int, vector<int>, greater<int> > pq;

	for(int i=0;i<x;i++)
	{
		pq.push(arr1[i]);
	}

	for(int i=x;i<n;i++)
	{
		if(arr1[i] > pq.top())
		{
			pq.pop();
			pq.push(arr1[i]);
		}
	}
	
	return pq.top();
}

int main()
{
	int arr1[] = {40,5,10,30,20,22,2,3,15,17,1,25};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int k = 3;
	cout << "kth largest element => " << kthLargest(arr1,n,k) << endl;

	return 0;
}