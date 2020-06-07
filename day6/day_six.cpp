#include <iostream>

using namespace std; 

#define V 4 
#define INF 999999

void printMinDistance(int res_dist[][V])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(res_dist[i][j] == INF)
			{
				cout << "INF" << " ";
			}
			else
			{
				cout << res_dist[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void floydWarshall(int adj[][V])
{
	int res_dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			res_dist[i][j] = adj[i][j];
		}
	}

	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				// If vertex k is on the shortest path from i to j, 
				// then update the value of res_dist[i][j]
				if(res_dist[i][k] + res_dist[k][j] < res_dist[i][j])
				{
					res_dist[i][j] = res_dist[i][k] + res_dist[k][j];
				}
			}
		}
	}
	printMinDistance(res_dist);
}

int main() 
{
	int adj[V][V] = { {0, 10, INF, 20}, 
						{INF, 0, 6, INF}, 
						{INF, INF, 0, 2}, 
						{INF, INF, INF, 0}
					  };
	floydWarshall(adj); 
	return 0; 
}