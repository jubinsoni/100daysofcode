# include <iostream>
# include <queue>

using namespace std;

void createMinQueue(int arr[],int n,queue<int> &qmin)
{
	if(min(arr[0],arr[1]) == arr[0])
	{
		qmin.push(arr[0]);
	}

	for(int i=1;i<=n-2;i++)
	{
		if(min(arr[i-1],arr[i]) == arr[i] && min(arr[i],arr[i+1]) == arr[i])
		{
			qmin.push(arr[i]);
		}
	}

	if(min(arr[n-2],arr[n-1]) == arr[n-1])
	{
		qmin.push(arr[n-1]);
	}
}

void createMaxQueue(int arr[],int n,queue<int> &qmax)
{
	if(max(arr[0],arr[1]) == arr[0])
	{
		qmax.push(arr[0]);
	}

	for(int i=1;i<=n-2;i++)
	{
		if(max(arr[i-1],arr[i]) == arr[i] && max(arr[i],arr[i+1]) == arr[i])
		{
			qmax.push(arr[i]);
		}
	}

	if(max(arr[n-2],arr[n-1]) == arr[n-1])
	{
		qmax.push(arr[n-1]);
	}
}

void stockBuyAndSell(int arr[],int n)
{
	queue<int> qmin;
	queue<int> qmax;
	createMinQueue(arr,n,qmin);
	createMaxQueue(arr,n,qmax);

	int buyingTotal = 0;
	cout << "buying numbers => ";
	while(qmin.empty() == false)
	{
		int temp = qmin.front();
		buyingTotal = buyingTotal + temp;
		cout << temp << " ";
		qmin.pop();
	}
	cout << endl;

	int sellingTotal = 0;
	cout << "selling numbers =>";
	while(qmax.empty() == false)
	{
		int temp = qmax.front();
		sellingTotal = sellingTotal + temp;
		cout << temp << " ";
		qmax.pop();
	}
	cout << endl;

	cout << "buyingTotal => " << buyingTotal << endl;
	cout << "sellingTotal => " << sellingTotal << endl;
	cout << "profitEarned => " << sellingTotal - buyingTotal << endl;
}

int main()
{
	int arr[] = {1,5,3,8,12};
	int size = sizeof(arr)/sizeof(arr[0]);
	stockBuyAndSell(arr,size);

	return 0;
}