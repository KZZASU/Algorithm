#include <iostream>
#include <vector>

using namespace std;

void permu(vector<int>& v, size_t j = 0)
{
	for (size_t i{ 0 }; i < v.size() - j; i++)
	{
		swap(v[j], v[i + j]);
		if (j < v.size() - 2)
		{
			permu(v, j + 1);
		}
		else
		{
			for (auto c : v) { cout << c << ' '; };
			cout << '\n';
		}
		swap(v[j], v[i + j]);
	}
}
