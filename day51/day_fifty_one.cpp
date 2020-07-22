# include <iostream>
# include <queue>
# include <vector>

using namespace std;

typedef pair<int, int> pi;

void mergeKSortedArraysApproachTwo(int k,int arr[][3],int row,int col)
{
	vector<int>indexTracker(row);
	priority_queue<pi,vector<pi>,greater<pi> > min_heap;
	vector<int>result;

	for(int i=0;i<row;i++)
	{
		min_heap.push(make_pair(arr[i][0],i));
	}

	pair<int,int> tempPair;
	while(result.size() < row*col)
	{
		tempPair.first = INT_MAX;
		tempPair.second = INT_MAX;
		tempPair = min_heap.top();
		min_heap.pop();
		result.push_back(tempPair.first);

		indexTracker[tempPair.second] = indexTracker[tempPair.second] + 1;
		
		if(indexTracker[tempPair.second] < col)
		{
			min_heap.push(make_pair(arr[tempPair.second][indexTracker[tempPair.second]],tempPair.second));
		}
	}

	cout << "mergeKSortedArraysApproachTwo => ";
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

void mergeKSortedArraysApproachOne(int k,int arr[][3],int row,int col)
{
	vector<int>indexTracker(row);
	vector<int>result;
	
	while(result.size() < row*col)
	{
		int min = INT_MAX;
		int min_indz = 0;
		for(int i=0;i<row;i++)
		{
			if(indexTracker[i] < col && min > arr[i][indexTracker[i]])
			{
				min = arr[i][indexTracker[i]];
				min_indz = i;
			}
		}

		indexTracker[min_indz] = indexTracker[min_indz] + 1;
		result.push_back(min);
	}

	cout << "mergeKSortedArraysApproachOne => ";
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

int main()
{
	int k = 3;
	int arr[][3] = {
					{3,5,7},
					{2,4,6},
					{0,8,9}
				};

	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(arr[0][0]);
	mergeKSortedArraysApproachOne(k,arr,row,col);
	mergeKSortedArraysApproachTwo(k,arr,row,col);
	return 0;
}