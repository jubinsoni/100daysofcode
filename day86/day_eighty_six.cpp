# include <iostream>

using namespace std;

int lenghtLCS(string str1,string str2,int m,int n)
{
	if(m ==0 || n == 0)
	{
		return 0;
	}

	if(str1[m-1] == str2[n-1])
	{
		return 1 + lenghtLCS(str1,str2,m-1,n-1);
	}
	else
	{
		return max(lenghtLCS(str1,str2,m-1,n),lenghtLCS(str1,str2,m,n-1));
	}

}

int LongestPalindromicSubSequence(string str1)
{
	string str2 = str1;
	reverse(str2.begin(),str2.end());

	int m = str1.length();
	int n = str2.length();

	return lenghtLCS(str1,str2,m,n);
}

int main()
{
	string str1 = "agbcba";

	cout << "LongestPalindromicSubSequence of " + str1 + " = ";
	cout << LongestPalindromicSubSequence(str1) << endl;

	cout << "-------------------" << endl;

	string str2 = "agbcba";
	cout << "# of Deletion in " + str2 + " to make it palindrome = ";
	cout << str2.length() - LongestPalindromicSubSequence(str2) << endl;

	cout << "-------------------" << endl;

	string str3 = "aebcbda";
	cout << "# of Deletion in " + str3 + " to make it palindrome = ";
	cout << str3.length() - LongestPalindromicSubSequence(str3) << endl;

	return 0;
}