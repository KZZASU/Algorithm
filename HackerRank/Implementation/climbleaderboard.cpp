#include <iostream>
#include <vector>
#include <algorithm>
#include "climbleaderboard.h"


//for every integer in player, rank(dense) the integer with the value in the ranked vector
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> result{};
	vector<int>::size_type j{ 0 };
	for (j; j < player.size(); j++)
	{
		vector<int>::size_type index{ 0 };
		vector<int> ranking{};
		int rank{ 1 };

		while ((ranked[index] > player[j]) && (index < ranked.size() - 1))
		{
			if (ranked[index] > ranked[index + 1])
			{
				rank++;
			}
			index++;
		}
		if (ranked[index] > player[j])
		{
			rank++;
		}

		result.push_back(rank);
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