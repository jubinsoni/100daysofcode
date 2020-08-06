# include <iostream>
# include <queue>

using namespace std;

// algo => always pick 2 numbers from the queue
// which are minimum 

int minCost(int arr[],int n)
{
	// creating min heap
	priority_queue<int,vector<int>,greater<int> > pq(arr,arr+n);

	int res = 0;

	while(pq.size() > 1)
	{
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		res = res + n1 + n2;
		pq.push(n1 + n2);
	}
	return res;
}

int main()
{
	int arr[] = {3,7,9,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "minCost => " << minCost(arr,n) << endl;

	return 0;
}