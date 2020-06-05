# include <iostream>
# include <unordered_set>

using namespace std;

int gcd(int a,int b)
{
	if(a ==0)
	{
		return b;
	}
	return gcd(b%a,a);
}


void uniqElem(int arr[],int size)
{
	unordered_set<int> us;
	int flag = 0;
	for(int i=0;i<size;i++)
	{
		if(us.find(arr[i]) == us.end())
		{
			us.insert(arr[i]);
		}
		else
		{
			flag = 1;
			cout << "array doesn't contains unique elements";
			break;
		}
	}
	if(flag == 0)
	{
		cout << "array contains unique elements";
	}
	cout << endl;

}

void uniqElem(string str)
{
	unordered_set<char> us;
	int flag = 0;
	for(int i=0;i<str.length();i++)
	{
		if(us.find(str[i]) == us.end())
		{
			us.insert(str[i]);
		}
		else
		{
			flag = 1;
			cout << "string doesn't contains unique elements";
			break;
		}
	}
	if(flag == 0)
	{
		cout << "string contains unique elements";
	}
	cout << endl;
}

template <typename T>
void uniqElemViaHashing(T arr[],int size)
{
	int hashArray[1000000] = {0};
	int flag = 0;
	for(int i=0;i<size;i++)
	{
		hashArray[arr[i]] = hashArray[arr[i]] + 1;
		if(hashArray[arr[i]] > 1)
		{
			flag = 1;
			cout << "doesn't contains unique elements";
			break;
		}
	}
	if(flag == 0)
	{
		cout << "contains unique elements";
	}
	cout << endl;
}

int main()
{
	cout << "gcd of 2 numbers => " << gcd(81,81) << endl;

	int arr1[] = {5,6,8,9,1,2,7,2,11,45,77,88};
	int arr2[] = {89,12,56,90,34,23,112,567,981};

	uniqElem(arr1,sizeof(arr1)/sizeof(arr1[0]));
	uniqElem(arr2,sizeof(arr2)/sizeof(arr2[0]));


	string str1 = "amvfsjowifnoz";
	string str2 = "ghkilnvbdfeqw";
	uniqElem(str1);
	uniqElem(str2);

	uniqElemViaHashing(arr1,sizeof(arr1)/sizeof(arr1[0]));
	uniqElemViaHashing(arr2,sizeof(arr2)/sizeof(arr2[0]));

	char strz1[] = "amvfsjowifnoz";
	char strz2[] = "ghkilnvbdfeqw";

	uniqElemViaHashing(strz1,sizeof(strz1)/sizeof(strz1[0]));
	uniqElemViaHashing(strz2,sizeof(strz2)/sizeof(strz2[0]));


	return 0;
}