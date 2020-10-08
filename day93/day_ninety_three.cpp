#include <bits/stdc++.h> 

using namespace std;

vector<pair<int, int> > createSkyline(vector<vector<int> >& buildings) 
{
	vector<pair<int, int> > wall;

	int left, height, right; 
	for (int i = 0; i < buildings.size(); i++)
	{
		left = buildings[i][0];
		height = buildings[i][1];
		right = buildings[i][2]; 

		// -ve height to indicate left wall
		wall.push_back(make_pair(left, -height));

		// +ve height to indicate right wall
		wall.push_back(make_pair(right, height)); 
	}

	sort(wall.begin(), wall.end()); 

	// to keep result
	vector<pair<int, int> > skyline; 

	// Initialize a multiset to keep left wall heights sorted
	// in mutiset we only store +ve heights always
	multiset<int> leftWallHeight = { 0 };

	int top = 0;

	for (auto w : wall)
	{ 

		// -ve means left wall
		// then we insert it into multiset 
		if (w.second < 0)
		{
			// -w.second coz -ve of -ve is +ve
			leftWallHeight.insert(-w.second); 
		}
		else // +ve means right wall...then we remove the correponding height
		{
			leftWallHeight.erase(leftWallHeight.find(w.second)); 
		}

		// top != leftWallHeight.rbegin()
		// rbegin() : this is reverse iterator
		if (top != *leftWallHeight.rbegin())
		{
			top = *leftWallHeight.rbegin(); 
			skyline.push_back(make_pair(w.first, top)); 
		}
	}

	return skyline; 
} 

void printSkyline(vector<vector<int> >& buildings) 
{
	vector<pair<int, int> > skyline = createSkyline(buildings); 
	cout << "Skyline => "; 
	for (auto it : skyline) 
	{
		cout << "{" << it.first << ", " << it.second << "} "; 
	} 
	cout << "}" << endl; 
} 

int main() 
{ 
	vector<vector<int> > buildings;

	buildings = { { 1, 11, 5 }, { 2, 6, 7 }, 
				{ 3, 13, 9 }, { 12, 7, 16 }, 
				{ 14, 3, 25 }, { 19, 18, 22 }, 
				{ 23, 13, 29 }, { 24, 4, 28 } }; 

	
	printSkyline(buildings); 
	
	return 0; 
} 
