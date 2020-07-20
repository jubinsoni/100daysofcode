# include <iostream>
# include <unordered_map>

using namespace std;

int countPair(int arr[],int n)
{
	unordered_map<int,int> umap;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		umap[arr[i]] = umap[arr[i]] + 1;
	}

	unordered_map<int,int>::iterator it;
	for(it=umap.begin();it!=umap.end();it++)
	{
		int n = it->second;
		if(n > 1)
		{
			count = count + (n*(n-1))/2;
		}
	}
	return count;
}

int main()
{
	int arr[] = {1,2,3,1,1,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "countPair => " << countPair(arr,n) << endl;
	return 0;
}