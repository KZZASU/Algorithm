#include <vector>
#include <iostream>

using namespace std;

void numofIslandAux(vector<vector<int>>&, size_t, size_t, vector<int>&);
int numofIsland(vector<vector<int>> Grid)
{
	/*1100
	  1101
	  0001
	  1100*/

	static size_t length_ = Grid.size();
	static vector<int> visited(length_ * length_);

	int num = 0;
	for (size_t i{ 0 }; i < length_; i++)
	{
		for (size_t j{ 0 }; j < length_; j++)
		{
			if ((visited[i * length_ + j] == 0) && (Grid[i][j] == 1))
			{
				num++;
				cout << "Island" << num << '\n';
			};
			numofIslandAux(Grid, i, j, visited);
		}
	}

	return num;
}

void numofIslandAux(vector<vector<int>>& Grid, size_t x, size_t y, vector<int>& visited)
{
	if (((x == Grid.size()) || (y == Grid.size())) || visited[x * Grid.size() + y] == 1)
	{
		return;
	}

	visited[x * Grid.size() + y] = 1;

	if ((Grid[x][y] == 1))
	{
		cout << x << ", " << y << '\n';
		numofIslandAux(Grid, x, y + 1, visited);
		numofIslandAux(Grid, x + 1, y, visited);
	}
	else
	{
		return;
	}
};