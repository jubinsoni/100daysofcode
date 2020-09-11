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

bool sequencePatternMatching(string str1,string str2)
{
	int m = str1.length();
	int n = str2.length();

	return lenghtLCS(str1,str2,m,n) == str1.length();
}

int main()
{
	string str1 = "AXY";
	string str2 = "ADXCPY";

	cout << "SequencePatternMatching of " + str1 + " and " + str2 + " = ";
	cout << sequencePatternMatching(str1,str2) << endl;

	return 0;
}