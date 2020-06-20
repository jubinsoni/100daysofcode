# include <iostream>
# include <unordered_set>

using namespace std;

string subArrayContainsSum(int arr[],int n,int x)
{
	unordered_set<int> us;
	int prefix_sum = 0;
	for(int i=0;i<n;i++)
	{
		prefix_sum = prefix_sum + arr[i];
		if(us.find(prefix_sum - x) == us.end())
		{
			us.insert(prefix_sum);
		}
		else
		{
			return "subArrayContainsSum";
		}
	}
	return "subArray Doesn't ContainsSum";
}

int main()
{
	int arr[] = {1,6,7,8,20,100};
	int x;
	x = 35;
	cout << "x = " << x << "," << subArrayContainsSum(arr,sizeof(arr)/sizeof(arr[0]),x) << endl;
	x = 18;
	cout << "x = " << x << "," << subArrayContainsSum(arr,sizeof(arr)/sizeof(arr[0]),x) << endl;
	return 0;
}