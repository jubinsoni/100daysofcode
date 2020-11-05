# include <bits/stdc++.h>

using namespace std;

struct disjointset
{
	int rnk;
	int parent;
};

int findset(struct disjointset d[],int vertex)
{
	if(d[vertex].parent != vertex)
	{
		d[vertex].parent = findset(d,d[vertex].parent);
	}

	return d[vertex].parent;
}

void unionset(int xp,int yp,struct disjointset d[])
{
	if(d[xp].parent > d[yp].parent)
	{
		d[yp].parent = d[xp].parent;
		d[xp].rnk = d[xp].rnk + 1;
	}
	else
	{
		d[xp].parent = d[yp].parent;
		d[yp].rnk = d[yp].rnk + 1;
	}
}

int main()
{
	int v = 9;
	int e = 14;

	// weight,(start,end)
	vector<pair<int,pair<int,int> > > edges;

	edges.push_back(make_pair(4,make_pair(0,1)));
	edges.push_back(make_pair(8,make_pair(0,7)));
	edges.push_back(make_pair(11,make_pair(1,7)));
	edges.push_back(make_pair(8,make_pair(1,2)));
	edges.push_back(make_pair(7,make_pair(7,8)));
	edges.push_back(make_pair(1,make_pair(7,6)));
	edges.push_back(make_pair(2,make_pair(2,8)));
	edges.push_back(make_pair(6,make_pair(8,6)));
	edges.push_back(make_pair(7,make_pair(2,3)));
	edges.push_back(make_pair(4,make_pair(2,5)));
	edges.push_back(make_pair(2,make_pair(6,5)));
	edges.push_back(make_pair(14,make_pair(3,5)));
	edges.push_back(make_pair(9,make_pair(3,4)));
	edges.push_back(make_pair(10,make_pair(5,4)));

	disjointset d[v+1];

	// first step
	for(int i=0;i<v;i++)
	{
		d[i].parent = i;
		d[i].rnk = i;
	}

	//2nd step
	sort(edges.begin(),edges.end());

	//3rd step
	vector<pair<pair<int,int>,int> > res;

	for(int i=0;i<e;i++)
	{
		int xp = findset(d,edges[i].second.first);
		int yp = findset(d,edges[i].second.second);

		if(xp == yp)
		{
			continue;// here cycle is detected within the graph
		}
		else
		{
			unionset(xp,yp,d);
			res.push_back(make_pair(make_pair(edges[i].second.first,edges[i].second.second),edges[i].first));
		}
	}

	//4th step
	int wt = 0;
	for(int i=0;i<res.size();i++)
	{
		wt = wt + res[i].second;

		cout << res[i].first.first << "----" << res[i].first.second << " " << res[i].second << endl;
	}

	cout << "MST wt => " << wt << endl;

	return 0;
}