#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int>  bfs(int n, int m, vector<vector<int>> edges, int s)
{
	vector<vector<int>> amat{};
	for (int j{ 0 }; j < n + 1; j++)
	{
		vector<int> row(n + 1);
		amat.push_back(row);
	}

	for (auto edge : edges)
	{
		amat[edge[0]][edge[1]]++;
		amat[edge[1]][edge[0]]++;
	}

	vector<int> result(n + 1, -1);

	vector<int> visited(n + 1);
	queue<int> q{};
	queue<int> p{};
	q.push(s);
	visited[s] = 1;
	cout << s << ' ';
	int depth = 1;
	while ((!q.empty()) || (!p.empty()))
	{
		int v = q.front();
		for (int k{ 0 }; k < n + 1; k++)
		{
			if ((amat[v][k] > 0) && (visited[k] == 0))
			{
				p.push(k);
				visited[k]++;

				result[k] = depth * 6;
			}
		}
		q.pop();

		if (q.empty())
		{
			q = p;
			p = {};
			depth++;
		}
	}

	vector<int> ret_ = {};
	for (int i{ 0 }; i < n + 1; i++)
	{
		if ((i != 0) && (i != s))
		{
			ret_.push_back(result[i]);
		}
	}

	return ret_;
}