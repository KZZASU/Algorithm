#include <iostream>
#include <vector>
#include <algorithm>
#include "climbleaderboard.h"

bool myfunction(int i, int j) { return (i > j); }

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> result{};
	vector<int>::size_type j{ 0 };
	for (j; j < player.size(); j++)
	{
		vector<int> ranked_copy{ ranked };
		ranked_copy.push_back(player[j]);
		sort(ranked_copy.begin(), ranked_copy.end(), myfunction);

		vector<int>::size_type index{ 0 };
		vector<int> ranking{};
		int rank{ 1 };
		for (index; index < ranked_copy.size() - 1; index++)
		{
			ranking.push_back(rank);
			if (ranked_copy[index] > ranked_copy[index + 1])
			{
				rank++;
			}
		}
		ranking.push_back(rank);

		for (size_t k{ 0 }; k < ranked_copy.size(); k++)
		{
			if (ranked_copy[k] == player[j])
			{
				result.push_back(ranking[k]);
				break;
			}
		}
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