# include <iostream>
# include <queue>

using namespace std;

void almostSorted(int arr[],int n,int k)
{
	// minheap
	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i=0;i<k+1;i++)
	{
		pq.push(arr[i]);
	}

	int itr = 0;
	for(int i=k+1;i<n;i++)
	{
		arr[itr] = pq.top();
		itr = itr + 1;
		pq.pop();
		pq.push(arr[i]);
	}

	while(pq.empty() == false)
	{
		arr[itr] = pq.top();
		itr = itr + 1;
		pq.pop();
	}

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

int main()
{
	int arr1[] = {9,8,7,18,19,17};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int k = 2;
	almostSorted(arr1,n,k);

	return 0;
}