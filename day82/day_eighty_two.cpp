# include <iostream>

using namespace std;

int lengthOfLCS(string str1,string str2,int m,int n)
{
	if(m == 0 || n == 0)
	{
		return 0;
	}

	if(str1[m-1] == str2[n-1])
	{
		return 1 + lengthOfLCS(str1,str2,m-1,n-1);
	}
	else // if()
	{
		return max(lengthOfLCS(str1,str2,m,n-1),lengthOfLCS(str1,str2,m-1,n));
	}
}

int main()
{
	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";

	int m = str1.length();
	int n = str2.length();

	cout << "lengthOfShortestCommonSuperSequence of " + str1 + " and " + str2 + " = ";
	cout << m + n - lengthOfLCS(str1,str2,m,n) << endl;

	return 0;
}