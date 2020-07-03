# include <iostream>
# include <stack>

using namespace std;

// create leftmax and rightmax array
// then for each i do min(leftmax[i],rightmax[i]) - arr[i]
void trappingRainWater(int arr[],int n)
{

	int leftMaxArr[n];
	int rightMaxArr[n];
	int resultWaterTrapped[n];

	int maxz = arr[0];
	for(int i=0;i<n;i++)
	{
		if(maxz < arr[i])
		{
			maxz = arr[i];
		}
		leftMaxArr[i] = maxz;
	}

	maxz = arr[n-1];
	for(int i=n-1;i>=0;i--)
	{
		if(maxz < arr[i])
		{
			maxz = arr[i];
		}
		rightMaxArr[i] = maxz;
	}

	for(int i=0;i<n;i++)
	{
		resultWaterTrapped[i] = min(leftMaxArr[i],rightMaxArr[i]) - arr[i];
	}

	int totalWaterTrapped = 0;
	cout << "totalWaterTrappedArr => "; 
	for(int i=0;i<n;i++)
	{
		cout << resultWaterTrapped[i] << " ";
		totalWaterTrapped = totalWaterTrapped + resultWaterTrapped[i];
	}
	cout << endl;

	cout << "totalWaterTrapped => " << totalWaterTrapped << endl;
}

int main()
{
	int arr[] = {3,0,1,2,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "originalArr => ";
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	trappingRainWater(arr,size);

	return 0;
}