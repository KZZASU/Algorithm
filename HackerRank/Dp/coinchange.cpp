#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getWaysAux(int n, vector<long>& sub_c, vector<vector<long long>>& H, int size);
long long getWays(int n, vector<long>& c)
{
	static int size_ = static_cast<int>(c.size());
	static vector<vector<long long>> countingHash(n);

	for (int i{ 1 }; i < n + 1; i++)
	{
		for (int j{ 0 }; j < size_; j++)
		{
			vector<long> sub_c{ &c[0], &c[j] + 1 };
			getWaysAux(i, sub_c, countingHash, size_);
		}
	}

	long long sum = 0;
	for (int j{ 0 }; j < size_; j++)
	{
		sum = sum + countingHash[n - 1][j];
	}
	return sum;
}

long long getWaysAux(int n, vector<long>& c, vector<vector<long long>>& H, int size_)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}

	if (H[n - 1].size() == size_)
	{
		long long sum = 0;
		for (int i{ 0 }; i < (int)(c.size()); i++)
		{
			sum += H[n - 1][i];
		}
		return sum;
	}
	else
	{
		long long cnt = 0;
		cnt = cnt + getWaysAux(n - c[c.size() - 1], c, H, size_);
		H[n - 1].push_back(cnt);
	}
	return 0;
};

int main()
{
	vector<long> v{ 2,3,5,6 };
	cout << getWays(13, v);
	return 0;
}