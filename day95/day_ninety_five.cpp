# include <bits/stdc++.h>

using namespace std;

int countPaths(int n,int m)
{
	if(n == 1 || m == 1)
	{
		return 1;
	}

	return countPaths(n,m-1) + countPaths(n-1,m) + countPaths(n-1,m-1);
}

int main()
{
	int n = 3;
	int m = 3;

	cout << "count ways from top left to bottom right of a ";
	cout << to_string(n) + "x" + to_string(m) + " is => ";
	cout << countPaths(n,m) << endl;

	return 0;
}