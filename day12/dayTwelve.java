public class dayTwelve
{
	public static int V = 9;

	public static void main(String args[])
	{
		int cost[][] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
		dijkstra(cost, 0, 5);
	}

	// we pick an unvisited vertex where distance is minimum
	public static int minDistance(int dist[], boolean visited[]) 
	{ 
		int min = Integer.MAX_VALUE;
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

	public static void dijkstra(int cost[][], int src,int dest) 
	{ 
		int dist[] = new int[V];
		boolean visited[] = new boolean[V]; // visited[i] = true if vertex i is processed

		// Initialize all distances as inf 
		// Initialize visited[] as false 
		for (int i = 0; i < V; i++)
		{
			dist[i] = Integer.MAX_VALUE;
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
				if (visited[v] == false && cost[u][v] > 0 && dist[u] != Integer.MAX_VALUE && dist[u] + cost[u][v] < dist[v])
				{
					dist[v] = dist[u] + cost[u][v];
				}
			}
		}

		System.out.print("shortest distance from src => " + src);
		for (int i = 0; i < V; i++)
		{
			if(i == dest)
			{
				System.out.println(" to dest=> " + dest + " ==> " + dist[i] );
			}
		}
	} 
}