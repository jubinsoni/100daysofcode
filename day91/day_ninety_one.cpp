# include <bits/stdc++.h>

using namespace std;

int arr[1000][1000] = {0};

int minz(int a,int b,int c)
{
	return min(min(a,b),c);
}

int editDistance(string str1,string str2,int m,int n)
{
	if(n == 0)
	{
		return m;
	}

	if(m == 0)
	{
		return n;
	}

	if(str1[m-1] == str2[n-1])
	{
		return editDistance(str1,str2,m-1,n-1);
	}
	else
	{
		return 1 + minz(editDistance( str1, str2,m-1,n-1),
						editDistance( str1, str2,m,n-1),
						editDistance( str1, str2,m-1,n));
	}
}

int editDistanceMemoization(string str1,string str2,int m,int n)
{
	if(n == 0)
	{
		return m;
	}

	if(m == 0)
	{
		return n;
	}

	if(arr[m][n] > 0)
	{
		return arr[m][n];
	}

	if(str1[m-1] == str2[n-1])
	{

		arr[m][n] = editDistance(str1,str2,m-1,n-1);
		cout << arr[m][n] << endl;
		return arr[m][n];
	}
	else
	{
		arr[m][n] =  1 + minz(editDistance( str1, str2,m-1,n-1),
								editDistance( str1, str2,m,n-1),
								editDistance( str1, str2,m-1,n));

		return arr[m][n];
	}
}

int main()
{
	string str1 = "food";
	int m = str1.length();
	string str2 = "money";
	int n = str2.length();
	cout << "editDistance from " + str1 + " to " + str2 + " is => "<< editDistanceMemoization(str1,str2,m,n) << endl;
	return 0;
}