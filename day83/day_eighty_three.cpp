# include <iostream>

using namespace std;


int lengthLCS(string str1,string str2,int m,int n)
{
	if(m ==0 || n == 0)
	{
		return 0;
	}

	if(str1[m-1] == str2[n-1])
	{
		return 1 + lengthLCS(str1,str2,m-1,n-1);
	}
	else
	{
		return max(lengthLCS(str1,str2,m,n-1),lengthLCS(str1,str2,m-1,n));
	}
}

int main()
{
	string str1 = "heap";
	string str2 = "pea";

	int m = str1.length();
	int n = str2.length();

	cout << "while converting " + str1 + " to " + str2 + "..." << endl;
	cout << "# of Deletion = " << m - lengthLCS(str1,str2,m,n) << endl;
	cout << "# of Insertion = " << n - lengthLCS(str1,str2,m,n) << endl;

	return 0;
}