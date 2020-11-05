# include <iostream>
# include <vector>
# include <queue>

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int n_vertex)
{
	vector<int>::iterator it;
	for(int i=0;i<n_vertex;i++)
	{
		cout << "vertex " << i << " : ";
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout << *it << " ";
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
	vector<int> :: iterator it;

	visited[s] = true;
	q.push(s);

	while(q.empty() == false)
	{
		int res = q.front();
		cout << res << " ";
		q.pop();

		for(it=adj[res].begin();it!=adj[res].end();it++)
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

void dfsUtil(vector<int> adj[],bool visited[],int s)
{
	cout << s << " ";
	visited[s] = true;

	vector<int>::iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(visited[*it] == false)
		{
			dfsUtil(adj,visited,*it);
		}
	}

}

void dfs(vector<int>adj[],int n_vertex,int s)
{
	bool *visited = new bool[n_vertex];

	for(int i=0;i<n_vertex;i++)
	{
		visited[i] = false;
	}

	dfsUtil(adj,visited,s);

	cout << endl;
}


int main()
{
	int n_vertex = 6;
	vector<int> adj[n_vertex];

	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,4);
	addEdge(adj,3,4);
	addEdge(adj,3,5);
	addEdge(adj,4,5);

	printGraph(adj,n_vertex);

	bfs(adj,n_vertex,0);
	dfs(adj,n_vertex,0);

	cout << "----------" << endl;
	

	return 0;
}