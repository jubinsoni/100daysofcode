# include <iostream>

using namespace std;

int arr[20][20];

int longestCommonSubsequenceMemoization(string str1,string str2,int n,int m)
{
	if(n == 0 || m == 0)
	{
		return 0;
	}

	if(arr[n][m] > 0)
	{
		return arr[n][m];
	}

	if(str1[m-1] == str2[n-1])
	{
		arr[n][m] = 1 + longestCommonSubsequenceMemoization(str1,str2,n-1,m-1);
		return arr[n][m];
	}
	else
	{
		arr[n][m] = max(longestCommonSubsequenceMemoization(str1,str2,n,m-1),longestCommonSubsequenceMemoization(str1,str2,n-1,m));
		return arr[n][m];
	}
}

string printLCSRecursive(string str1,string str2,int i,int j)
{
	if(i == 0 || j == 0)
	{
		return "";
	}

	if(str1[i-1] == str2[j-1])
	{
		return str1[i-1] + printLCSRecursive( str1, str2, i-1, j-1);
	}
	else
	{
		if(arr[i-1][j] > arr[i][j-1])
		{
			return printLCSRecursive( str1, str2, i-1, j);
		}
		else //if(arr[i][j-1] > arr[i-1][j])
		{
			return printLCSRecursive( str1, str2, i, j-1);
		}
	}
}

string printLCSIteratively(string str1,string str2,int i,int j,string res)
{
	while(i > 0 && j > 0)
	{
		if(str1[i-1] == str2[j-1])
		{
			res = res + str1[i-1];
			i = i - 1;
			j = j - 1;
		}
		else
		{
			if(arr[i-1][j] > arr[i][j-1])
			{
				i = i - 1;
			}
			else //if(arr[i][j-1] > arr[i-1][j])
			{
				j = j - 1;
			}
		}
	}

	return res;
}

int main()
{
	string str1 = "abcdgh";
	string str2 = "abedfhr";

	int n = str1.length();
	int m = str2.length();

	// initializion
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			arr[i][j] = 0;
		}
	}

	// calling CountlongestCommonSubsequenceMemoization
	longestCommonSubsequenceMemoization(str1,str2,n,m);

	cout << "printing memoized table : " << endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	string res1 = printLCSRecursive(str1, str2,n,m);
	reverse(res1.begin(),res1.end());
	cout << "printLCSRecursive of " + str1 + " and " + str2 + " => " << res1 << endl;


	string res2 = printLCSIteratively(str1, str2,n,m,"");
	reverse(res2.begin(),res2.end());
	cout << "printLCSIteratively of " + str1 + " and " + str2 + " => " << res1 << endl;

	return 0;
}