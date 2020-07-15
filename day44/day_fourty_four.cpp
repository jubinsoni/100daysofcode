# include <iostream>
# include <unordered_set>

using namespace std;

void findTripletMethod1(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		unordered_set<int> us;
		for(int j=0;j<n;j++)
		{
			if(j == i)
			{
				continue;
			}
			if(us.find(x - arr[i] - arr[j]) == us.end())
			{
				us.insert(arr[j]);
			}
			else
			{
				cout << "Triplet found => " << arr[i] << ",";
				cout << arr[j] << "," << x-arr[i]-arr[j] << endl;
				return;
			}
		}
	}
}

void findTripletMethod2(int arr[],int n,int x)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		int left = i + 1;
		int right = n - 1;
		while(left < right)
		{
			if(arr[left] + arr[right] + arr[i] == x)
			{
				cout << "Triplet found => " << arr[i] << ",";
				cout << arr[left] << "," << arr[right] << endl;
				return ;
			}
			else if(arr[left] + arr[right] + arr[i] < x)
			{
				left = left  + 1;
			}
			else if(arr[left] + arr[right] + arr[i] > x)
			{
				right = right - 1;
			}
		}
	}
}

int main()
{
	int arr[] = {22,100,12,4,7,77,54};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 23;
	cout << "Method 1(without sorting and using unordered_set):: ";
	findTripletMethod1(arr,size,x);
	cout << "Method 2(sorting and usnig 2 pointer algo):: ";
	findTripletMethod2(arr,size,x);
	return 0;
}