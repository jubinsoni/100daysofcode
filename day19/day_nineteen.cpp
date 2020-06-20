# include <iostream>
# include <unordered_set>

using namespace std;

string arrayContainsPairSum(int arr[],int n,int x)
{
	unordered_set<int> us;
	for(int i=0;i<n;i++)
	{
		if(us.find(x-arr[i]) == us.end())
		{
			us.insert(arr[i]);
		}
		else
		{
			return "arrayContainsPairSum";
		}
	}
	return "Doesn't contains PairSum";
}

int main()
{
	int arr[] = {1,6,7,8,20,100};
	int x;
	x = 12;
	cout << "x = " << x << "," << arrayContainsPairSum(arr,sizeof(arr)/sizeof(arr[0]),x) << endl;
	x = 15;
	cout << "x = " << x << "," << arrayContainsPairSum(arr,sizeof(arr)/sizeof(arr[0]),x) << endl;

	return 0;
}