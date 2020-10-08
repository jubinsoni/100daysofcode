#include <bits/stdc++.h> 

# define ROW 100
# define COL 100

using namespace std;

bool isSafe(string M[], int i, int j,bool visited[ROW][COL],char ch,int row_length,int col_length)
{ 
	// i is within row limit
	// j is within col limit
	// value is 1 and visited  is false
	if(	(i >= 0 && i < row_length) && 
		(j >= 0 && j < col_length) && 
		(M[i][j] == ch && visited[i][j] == false)	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DFS(string M[], int i, int j,bool visited[ROW][COL],char ch,int row_length,int col_length)
{
	// all 4 neighbours index
	static int row_nbr_ind[] = { -1, 1, 0, 0 }; 
	static int col_nbr_ind[] = { 0, 0, 1, -1 }; 

	// Mark this cell as visited 
	visited[i][j] = true; 

	// iterate over all eight neighbours 
	for (int k = 0; k < 4;k++)
	{
		if (isSafe(M, i + row_nbr_ind[k], j + col_nbr_ind[k], visited,ch,row_length,col_length) == true)
		{
			DFS(M, i + row_nbr_ind[k], j + col_nbr_ind[k], visited,ch,row_length,col_length);
		}
	}
} 

int countIslands(string M[],int row_length,int col_length)
{ 
	// Make a bool array to mark visited cells. 
	// Initially all cells are unvisited
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited)); 

	// Initialize count as 0  
	// travese through given matrix 
	int count = 0; 
	for (int i=0;i<row_length;i++)
	{
		for (int j=0;j<col_length;j++)
		{
			char ch = M[i][j];
			if (M[i][j] == ch && visited[i][j] == false)
			{
				DFS(M, i, j, visited,ch,row_length,col_length);
				count = count + 1; 
			}
		}
	}
	return count; 
}

int main()
{
	string M[] = {"aabba", "aabba", "aaaca"}; 
    int row_length = sizeof(M)/sizeof(M[0]);
    int col_length = M[0].length();
  
    cout << "Number of islands => " << countIslands(M,row_length,col_length) << endl;

	return 0; 
}

