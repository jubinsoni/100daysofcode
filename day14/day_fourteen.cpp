# include <iostream>

using namespace std;


void allPair(string str,string curr,int index)
{
	if(str.length() == index)
	{
		cout << curr << " ";
		return;
	}
	allPair(str,curr,index+1);
	allPair(str,curr + str[index],index+1);
}

void permute(string str,int l,int r)
{
	if(l == r)
	{
		cout << str << " ";
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(str[l],str[i]);
			permute(str,l+1,r);
			swap(str[l],str[i]);
		}
	}
}

int main()
{
	string str = "ABC";
	allPair(str,"",0);
	cout << endl;
	permute(str,0,str.length()-1);
	cout << endl;
	return 0;
}