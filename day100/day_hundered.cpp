# include <iostream>

# define INF 99999
# define v 4

using namespace std;

void printArr(int res[v][v])
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

void floydWarshall(int adj[v][v])
{
	int res[v][v];

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			res[i][j] = adj[i][j];
		}
	}

	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(res[i][k] + res[k][j] < res[i][j])
				{
					res[i][j] =  res[i][k] + res[k][j];
				}
			}
		}
	}

	printArr(res);
}

int main()
{
	int adj[v][v] = {
						{0,10,INF,20},
						{INF,0,6,INF},
						{INF,INF,0,2},
						{INF,INF,INF,0}
					};

	floydWarshall(adj);

	return 0;
}