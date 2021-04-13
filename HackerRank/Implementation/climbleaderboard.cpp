#include <iostream>
#include <vector>
#include <algorithm>
#include "climbleaderboard.h"


//for every integer in player, rank(dense) the integer with the value in the ranked vector
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> result{};
	int j{ static_cast<int>(player.size() - 1) };
	vector<int>::size_type k{ ranked.size() };
	vector<int>::size_type index{ 0 };
	vector<int> ranking{};

	int rank{ 1 };
	ranked.push_back(0);
	while ((index < k) && j >= 0)
	{
		while (ranked[index] <= player[j])
		{
			result.insert(result.begin(), rank);
			j--;
		}
		if (ranked[index] > ranked[index + 1])
		{
			rank++;
		}
		index++;
	}

	while ((ranked[index] == 0) && (j >= 0))
	{
		result.insert(result.begin(), rank);
		j--;
	}

	return result;
}


int main()
{
	vector<int> ranked{ 100,90,90,80,75,60 };
	vector<int> player{ 50,65,77,90,102 };
	vector<int> result{ climbingLeaderboard(ranked, player) };
	for (int j{ 0 }; j < (int)(result.size()); j++)
	{
		cout << result[j] << ' ';
	}
	return 0;
}