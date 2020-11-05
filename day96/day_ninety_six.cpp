# include <iostream>
# include <unordered_set>

using namespace std;

int gcd(int a,int b)
{
	if(a == 0)
	{
		return b;
	}
	return gcd(b%a,a);
}

bool isPrime(int n)
{
	if(n == 2)
	{
		return true;
	}

	if(n == 0 || n == 1 || n%2 == 0)
	{
		return false;
	}

	for(int i=3;i*i <= n ;i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}

	return true;
}

void allPair(string str,string curr,int index)
{
	if(str.length() == index)
	{
		cout << curr << " ";
		return;
	}

	allPair(str,curr,index+1);
	allPair(str,curr+str[index],index+1);
}

void permute(string str,int l,int r)
{
	if(l == r)
	{
		cout << str << " ";
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(str[l],str[i]);
			permute(str,l+1,r);
			swap(str[l],str[i]);
		}
	}
}

bool binarySearch(int arr[],int x,int left,int right)
{
	if(left <= right)
	{
		int mid = left + (right-left)/2;
		if(arr[mid] == x)
		{
			return true;
		}
		else if(arr[mid] > x)
		{
			return binarySearch(arr,x,left,mid-1);
		}
		else if(arr[mid] < x)
		{
			return binarySearch(arr,x,mid+1,right);
		}
	}

	return false;
}

bool subArrayContainsSum(int arr[],int n,int x)
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
			return true;
		}
	}
	return false;
}

bool arrayContainsPair(int arr[],int n,int x)
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
			return true;
		}
	}

	return false;
}

void printArr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void selectionSort(int arr[],int n)
{
	for(int  i=0;i<=n-2;i++)
	{
		int minindz = i;
		for(int j=i+1;j<=n-1;j++)
		{
			if(arr[minindz] > arr[j])
			{
				minindz = j;
			}
		}
		swap(&arr[minindz],&arr[i]);
	}
}

int main()
{
	cout << "gcd of "<< 3 << "," << 9 << " is " << gcd(3,9) << endl;
	cout << "---------------------" << endl;
	cout << "isPrime(9) " << isPrime(9) << endl;
	cout << "---------------------" << endl;
	string str1 = "abc";
	allPair(str1,"",0);
	cout << endl;
	cout << "---------------------" << endl;
	permute(str1,0,str1.length()-1);
	cout << endl;
	cout << "---------------------" << endl;
	int arr1[] = {3,7,9,99,100};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << binarySearch(arr1,5,0,n1-1) << endl;
	cout << binarySearch(arr1,7,0,n1-1) << endl;
	cout << "---------------------" << endl;
	cout << "subArrayContainsSum => " << subArrayContainsSum(arr1,n1,16) << endl;
	cout << "---------------------" << endl;
	cout << "arrayContainsPair => " << arrayContainsPair(arr1,n1,103) << endl;
	cout << "---------------------" << endl;
	int arr2[] = {9,6,10,12,4,3};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	bubbleSort(arr2,n2);
	printArr(arr2,n2);

	int arr3[] = {9,6,10,12,4,3};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	selectionSort(arr3,n3);
	printArr(arr3,n3);
	cout << "---------------------" << endl;

	return 0;
}