# include <iostream>
# include <queue>

using namespace std;

void almostSorted(int arr[],int n,int k)
{
	// minheap
	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i=0;i<k;i++)
	{
		pq.push(arr[i]);
	}

	for(int i=0;i<k-1;i++)
	{
		cout << "_" << " ";
	}

	cout << pq.top() << " ";
	pq.pop();

	for(int i=k;i<n;i++)
	{
		pq.push(arr[i]);
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}

int main()
{
	int arr1[] = {10, 20, 11, 70, 50, 40, 100, 50};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int k = 3;
	almostSorted(arr1,n,k);

	return 0;
}