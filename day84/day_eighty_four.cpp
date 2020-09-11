# include <iostream>

using namespace std;

int longestRepeatingSubsequence(string str1,string str2,int m,int n)
{
	if(m == 0 || n == 0)
	{
		return 0;
	}

	if(str1[m-1] == str2[n-1] && m != n)
	{
		return 1 + longestRepeatingSubsequence(str1,str2,m-1,n-1);
	}
	else
	{
		return max(longestRepeatingSubsequence(str1,str2,m,n-1),longestRepeatingSubsequence(str1,str2,m-1,n));
	}

}

int main()
{
	string str1 = "AABEBCDD";

	cout << "longestRepeatingSubsequence of " + str1 + " = " << longestRepeatingSubsequence(str1,str1,str1.length(),str1.length()) << endl;

	return 0;
}