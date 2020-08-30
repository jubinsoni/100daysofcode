# include <iostream>

using namespace std;

int longestCommonSubsequence(string str1,string str2,int n,int m)
{
	if(n == 0 || m == 0)
	{
		return 0;
	}

	if(str1[m-1] == str2[n-1])
	{
		return 1 + longestCommonSubsequence(str1,str2,n-1,m-1);
	}
	else
	{
		return max(longestCommonSubsequence(str1,str2,n,m-1),longestCommonSubsequence(str1,str2,n-1,m));
	}
}

int arr[20][20] = {0};

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
		arr[n][m] = 1 + longestCommonSubsequence(str1,str2,n-1,m-1);
		return arr[n][m];
	}
	else
	{
		arr[n][m] = max(longestCommonSubsequence(str1,str2,n,m-1),longestCommonSubsequence(str1,str2,n-1,m));
		return arr[n][m];
	}
}

int main()
{
	string str1 = "abcdgh";
	string str2 = "abedfhr";

	int n = str1.length();
	int m = str2.length();

	cout << "longestCommonSubsequence of " + str1 + " and " + str2 + "(recursive) => " << longestCommonSubsequence(str1,str2,n,m) << endl;
	cout << "longestCommonSubsequence of " + str1 + " and " + str2 + "(recursive + memoization) => ";
	cout << longestCommonSubsequenceMemoization(str1,str2,n,m) << endl;

	return 0;
}