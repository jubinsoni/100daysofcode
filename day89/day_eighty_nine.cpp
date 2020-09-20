# include <bits/stdc++.h>

using namespace std;

int eggDroppingProblem(int e,int f)
{
	if(f==0 || f == 1 || e == 1)
	{
		return f;
	}

	int min_comp = INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp = 1 + max(eggDroppingProblem(e-1,k-1),eggDroppingProblem(e,f-k));
		min_comp = min(min_comp,temp);
	}

	return min_comp;
}

int main()
{
	int f = 5;
	int e = 3;

	cout << "Minimum No of tries to find threshold floor ";
	cout << "for f=" << f << " and " << "e=" << e << " => ";
	cout << eggDroppingProblem(e,f) << endl;

	return 0;
}