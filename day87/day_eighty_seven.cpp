# include <iostream>

using namespace std;

int arr[10][10];

int memoizationLengthOfLCS(string str1,string str2,int m,int n)
{
	if(m == 0 || n == 0)
	{
		return 0;
	}

	if(arr[m][n] > 0) 
	{
		return arr[m][n];
	}

	if(str1[m-1] == str2[n-1])
	{
		arr[m][n] = 1 + memoizationLengthOfLCS(str1,str2,m-1,n-1);
		return arr[m][n];
	}
	else
	{
		arr[m][n] = max(memoizationLengthOfLCS(str1,str2,m,n-1),memoizationLengthOfLCS(str1,str2,m-1,n));
		return arr[m][n];
	}
}

void printingShortestCommonSubsequence(string str1,string str2,int m,int n)
{
	string res = "";

	while(m > 0 && n > 0)
	{
		if(str1[m-1] == str2[n-1])
		{
			res.push_back(str1[m-1]);
			m = m - 1;
			n = n - 1;
		}
		else if(arr[m-1][n] > arr[m][n-1])
		{
			res.push_back(str1[m-1]);
			m = m - 1;
		}
		else if(arr[m][n-1] > arr[m-1][n])
		{
			res.push_back(str2[n-1]);
			n = n - 1;
		}
	}

	// handling early stop phenomenon
	while(m > 0)
	{
		res.push_back(str1[m-1]);
	}

	while(n > 0)
	{
		res.push_back(str2[n-1]);
	}

	reverse(res.begin(),res.end());

	cout << "shortestCommonSubsequence of " + str1 + " and " + str2 + " => ";
	cout << res << endl;
}

void printMemoizedTable()
{
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	string str1 = "acbcf";
	string str2 = "abcdaf";

	int m = str1.length();
	int n = str2.length();

	// initialization
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j] = 0;
		}
	}

	memoizationLengthOfLCS(str1,str2,m,n);

	cout << "printing Memoized Table : " << endl; 
	printMemoizedTable();

	printingShortestCommonSubsequence(str1,str2,m,n);

	return 0;
}