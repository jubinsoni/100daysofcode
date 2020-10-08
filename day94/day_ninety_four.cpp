#include <bits/stdc++.h> 

using namespace std; 

#define ROW 5 
#define COL 5 

bool isSafe(int M[][COL], int i, int j,bool visited[][COL]) 
{ 
	// i is within row limit
	// j is within col limit
	// value is 1 and visited  is false
	if(	((i >= 0) && (i < ROW)) && 
		((j >= 0) && (j < COL)) && 
		(M[i][j] == 1 && visited[i][j] == false)	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DFS(int M[][COL], int i, int j,bool visited[][COL]) 
{
	// all eight neighbours index
	static int row_nbr_ind[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	static int col_nbr_ind[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

	// Mark this cell as visited 
	visited[i][j] = true; 

	// iterate over all eight neighbours 
	for (int k = 0; k < 8;k++)
	{
		if (isSafe(M, i + row_nbr_ind[k], j + col_nbr_ind[k], visited) == true)
		{
			DFS(M, i + row_nbr_ind[k], j + col_nbr_ind[k], visited);
		}
	}
} 

int countIslands(int M[][COL]) 
{ 
	// Make a bool array to mark visited cells. 
	// Initially all cells are unvisited 
	bool visited[ROW][COL]; 
	memset(visited, 0, sizeof(visited)); 

	// Initialize count as 0  
	// travese through given matrix 
	int count = 0; 
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (M[i][j] == 1 && visited[i][j] == false)
			{
				DFS(M, i, j, visited);
				count = count + 1; 
			}
		}
	}
	return count; 
}

int main() 
{
	int M[ROW][COL] = { { 1, 1, 0, 0, 0 }, 
					{ 0, 1, 0, 0, 1 }, 
					{ 1, 0, 0, 1, 1 }, 
					{ 0, 0, 0, 0, 0 }, 
					{ 1, 0, 1, 0, 1 } }; 

	cout << "Number of islands => " << countIslands(M) << endl;


	return 0; 
}

