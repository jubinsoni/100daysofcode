# include <iostream>

using namespace std;

int max3Num(int a,int b,int c)
{
	return max(a,max(b,c));
}

int longestContiguousSubString(string str1,string str2,int n,int m,int count)
{
	if(n == 0 || m == 0)
	{
		return count;
	}

	// coding choice diagram

	// if last character matches => increase count
	if(str1[n-1] == str2[m-1])
	{
		count = count + 1;
		return longestContiguousSubString(str1,str2,n-1,m-1,count);
	}
	else // if last character does not matches then max(count1,count2,count3)
	{
		// count1 = count
		// count2 = longestContiguousSubString(str1,str2,n,m-1,0)
		// count3 = longestContiguousSubString(str1,str2,n-1,m,0)
		return max3Num(count,longestContiguousSubString(str1,str2,n,m-1,0),longestContiguousSubString(str1,str2,n-1,m,0));
	}
}

int main()
{
	string str1 = "abcdefxyz";
	string str2 = "xyzabcdefsdsds";

	int n = str1.length();
	int m = str2.length();

	cout << "longestContiguousSubString of " << str1 + " and " + str2 + " is " ;
	cout << longestContiguousSubString(str1,str2,n,m,0) << endl;

	return 0;
}