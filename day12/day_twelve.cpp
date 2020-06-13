// Dijkstra's single source shortest path algorithm when cost is represented as  adjacency matrix 
// Time complexity is O(V^2) and it doesn't work for graphs with negative weights

# include <iostream>
# define V 9 

using namespace std;

// we pick an unvisited vertex where distance is minimum
int minDistance(int dist[], bool visited[]) 
{ 
	int min = INT_MAX;
	int min_index = -1;
	for (int v = 0; v < V; v++)
	{
		if (visited[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}

	return min_index; 
} 

void dijkstra(int cost[V][V], int src,int dest) 
{ 
	int dist[V];
	bool visited[V]; // visited[i] = true if vertex i is processed

	// Initialize all distances as inf 
	// Initialize visited[] as false 
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	// distance from src to itself is 0
	dist[src] = 0; 

	for (int vertex = 0; vertex < V - 1; vertex++) 
	{ 
		// we pick an unvisited vertex where distance is minimum
		int u = minDistance(dist, visited);

		if(u == dest)
		{
			break;
		}

		visited[u] = true; 
		// u is intermeidate source vertex
		// v is intermediate destination vertex
		for (int v = 0; v < V; v++) 
		{
			// if visited[v] == false i.e vertex not visited
			// if there exist a value in cost[u][v]
			// if dist[u] != INT_MAX => if intermeidate source has distance value not as INT_MAX
			// if dist[u] + cost[u][v] < dist[v] => 
			// intermeidate source distance value + cost(source->destination) < intermediated destination distance value
			// then update the intermediated destination distance
			if (visited[v] == false && cost[u][v] > 0 && dist[u] != INT_MAX && dist[u] + cost[u][v] < dist[v])
			{
				dist[v] = dist[u] + cost[u][v];
			}
		}
	}

	cout << "shortest distance from src => " << src ;
	for (int i = 0; i < V; i++)
	{
		if(i == dest)
		{
			cout << " to dest=> " << dest << " ==> " << dist[i] << endl;
		}
	}
} 

int main() 
{
	int cost[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(cost, 0, 5); 

	return 0; 
} 
