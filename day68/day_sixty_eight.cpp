# include <iostream>

using namespace std;

# define MAX 1000

// count no of ways to reach a destination if we can take 1,2 or 3 steps

int noOfWaysToReachDestination(int n)
{
	int count[MAX] = {0};

	count[0] = 1;
	count[1] = 1;
	count[2] = 2;

	int res = 0;

	for(int i=3;i<=n;i++)
	{
		count[i] = count[i-1] + count[i-2] + count[i-3];
		res = count[i];
	}

	return res;
}

int arr[1000] = {0};

int noOfWaysToReachDestinationRecursive(int n)
{
	if(n < 0)
	{
		return 0;
	}

	if(n == 0)
	{
		return 1;
	}

	if(arr[n] > 0)
	{
		return arr[n];
	}

	arr[n] = noOfWaysToReachDestinationRecursive(n-1) + noOfWaysToReachDestinationRecursive(n-2) + noOfWaysToReachDestinationRecursive(n-3);

	return arr[n];
}

int main()
{

	int n1 = 3;
	cout << "noOfWaysToReachDestination => " << noOfWaysToReachDestination(n1) << endl;

	int n2 = 4;
	cout << "noOfWaysToReachDestination => " << noOfWaysToReachDestination(n2) << endl;

	int n3 = 4;
	cout << "noOfWaysToReachDestinationRecursive => " << noOfWaysToReachDestinationRecursive(n3) << endl;

	return 0;
}