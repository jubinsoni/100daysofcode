# include <iostream>
# include <queue>

using namespace std;
// O(nlogn)
int main()
{
	double arr[] = {5, 25, 15, 40, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	//max heap
	priority_queue<double> max_heap; 

	//min heap
	priority_queue<double,vector<double>,greater<double> > min_heap;

	max_heap.push(arr[0]);
	double median = max_heap.top();

	cout << median << " ";

	for(int i=1;i<n;i++)
	{
		if(max_heap.size() > min_heap.size())
		{
			if(arr[i] > median)
			{
				min_heap.push(arr[i]);
			}
			else
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(arr[i]);
			}
			median = (max_heap.top() + min_heap.top())/2;
		}
		else if(max_heap.size() < min_heap.size())
		{
			if(arr[i] < median)
			{
				max_heap.push(arr[i]);
			}
			else
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(arr[i]);
			}
			median = (max_heap.top() + min_heap.top())/2;
		}
		else if(max_heap.size() == min_heap.size())
		{
			if(arr[i] < median)
			{
				max_heap.push(arr[i]);
				median = max_heap.top();
			}
			else
			{
				min_heap.push(arr[i]);
				median = min_heap.top();
			}
		}
		cout << median << " ";
	}
	cout << endl;

	return 0;
}