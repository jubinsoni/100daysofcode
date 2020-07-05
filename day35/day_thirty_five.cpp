# include <iostream>
using namespace std;
void print3EqualArrays(int arr[],int leftInd,int rightInd,int n)
{
	cout << "1st array => ";
	for(int i=0;i<leftInd+1;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "2nd array => ";
	for(int i=leftInd+1;i<rightInd;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "3rd array => ";
	for(int i=rightInd;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool isDividableInto3EqualSum(int arr[],int n)
{
	int prefix_sum[n];
	int suffix_sum[n];
	int sumz = 0;
	for(int i=0;i<n;i++)
	{
		sumz = sumz + arr[i];
		prefix_sum[i] = sumz;
	}

	sumz = 0;
	for(int i=n-1;i>=0;i--)
	{
		sumz = sumz + arr[i];
		suffix_sum[i] = sumz;
	}

	int leftInd = -1;
	int rightInd = -1;

	for(int i=0;i<n;i++)
	{
		if(prefix_sum[i] == sumz/3)
		{
			leftInd = i;
			break;
		}
	}

	for(int i=n-1;i>=0;i--)
	{
		if(suffix_sum[i] == sumz/3)
		{
			rightInd = i;
			break;
		}
	}

	if(leftInd != -1 && rightInd != -1)
	{
		if((prefix_sum[rightInd-1] - prefix_sum[leftInd]) == sumz/3)
		{
			print3EqualArrays(arr,leftInd,rightInd,n);
			return true;
		}
		return false;
	}
	return false;
}

int main()
{
	int arr[] = { 2, 6, 12, 4, 14, 2, 4, 16 };
	int size = sizeof(arr)/sizeof(arr[0]);
	int temp = isDividableInto3EqualSum(arr,size);
	cout << "isDividableInto3EqualSum => " << temp << endl;
	return 0;
}