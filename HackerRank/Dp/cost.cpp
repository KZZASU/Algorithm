#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int cost(const vector<int>& B)
{
	int cost_ = 0;
	const int size_ = static_cast<int>(B.size());

	vector<int> s0{ 0,0 };
	int i{ 2 };
	while (i < size_ + 1)
	{
		int length_ = static_cast<int>(pow(2, i));
		vector<int> s1(length_);

		vector<int> add{};
		add.push_back(abs(B[i - 1] - B[i - 2]));
		add.push_back(abs(1 - B[i - 2]));
		add.push_back(abs(B[i - 1] - 1));
		add.push_back(abs(1 - 1));

		for (int j{ 0 }; j < length_; j++)
		{
			s1[j] = s0[j / 2] + add[j % 4];
		}
		s0 = s1;
		i++;
	}

	cost_ = *max_element(s0.begin(), s0.end());

	return cost_;
}



int main()
{
	vector<int> B{ 39, 99, 55, 47, 17, 53, 86, 33, 95, 72, 45, 56 };
	cout << cost(B);
	return 0;
}