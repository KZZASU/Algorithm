#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long getWays(int n, vector<long> c, vector<int>& r);

void bugetWays(int n, vector<long> c)
{
	static vector<int> CountingHash(n+1);
	CountingHash[0] = 0;

	for (int i{ 1 }; i < n+1; i++)
	{
		CountingHash[i] = getWays(i, c, CountingHash);
	}
	
	for (int j{n}; j >0; j--)
	{
		CountingHash[j] = CountingHash[j] - CountingHash[j - 1];
	}

	for (int i{ 0 }; i < n+1; i++)
	{
		cout << CountingHash[i] << ' ';
	}
}

long getWays(int n, vector<long> c, vector<int>& r) 
{
	static vector<long> v{};
	int size_ = static_cast<int>(c.size());
	static int count{ 0 };
	if (r[n] >= 1)
	{
		cout << "Hash Called\n";
		return r[n];
	}
	if (n == 0)
	{
		count++;
		//for (int j{0}; j < (int)v.size(); j++)
		//{
		//	cout << v[j] << ' ';
		//}
		//cout << '\n';
	
	}
	else
	{
		for (int i{ 0 }; i < size_; i++)
		{
			v.push_back(n);
			if (n - c[i] >= 0)
			{
				getWays(n - c[i], c, r);
			}
			v.pop_back();
		}
	}
	return count;
}

int main()
{
	vector<long> v{ 2,3,5,6 };
	bugetWays(6, v);
	return 0;
}