# include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void printGraph(vector<int> adj[],int n_vertex)
{
	for(int i=1;i<=n_vertex;i++)
	{
		cout << "adjacency list of vertex" << i ;
		for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout << "->" << *it;
		}
		cout << endl;
	}
}

void bfs(vector<int> adj[],int n_vertex,int s)
{
	bool *visited = new bool[n_vertex];
	for(int i=0;i<n_vertex;i++)
	{
		visited[i] = false;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);
	vector<int>::iterator it;
	while(q.empty() == false)
	{
		s = q.front();
		cout << s << " ";
		q.pop();
		for(it = adj[s].begin();it!=adj[s].end();it++)
		{
			if(visited[*it] == false)
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	cout << endl;
}

void DFSUtil(vector<int> adj[],int s,bool visited[])
{
	visited[s] = true;
	cout << s << " ";
	vector<int>::iterator it;
	for(it = adj[s].begin();it!=adj[s].end();it++)
	{
		if(visited[*it] == false)
		{
			DFSUtil(adj,*it,visited);
		}
	}
}

void dfs(vector<int> adj[],int n_vertex,int s)
{
	bool *visited = new bool[n_vertex];
	for(int i=0;i<n_vertex;i++)
	{
		visited[i] = false;
	}

	DFSUtil(adj,s,visited);
	cout << endl;
}

int main()
{
	int n_vertex = 6;
	vector<int> adj[n_vertex];
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,4);
	addEdge(adj,2,5);
	addEdge(adj,3,5);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	addEdge(adj,5,6);
	printGraph(adj,n_vertex);
	bfs(adj,n_vertex,1);
	dfs(adj,n_vertex,1);
	return 0;
}