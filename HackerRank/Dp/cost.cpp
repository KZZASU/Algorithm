#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

class Aux
{
public:
	Aux(int val,int idx) :value{ val }, index{idx}{};
	Aux() :value{ 0 }, index{ 0 }{};
	int value;
	int index;
};

int cost(const vector<int>& B)
{
	vector<vector<int>> S{};
	int size_ = static_cast<int>(B.size());
	int cost_{0};

	for (int i{ 1 }; i < size_; i++)
	{
		vector<int> a{};
		a.push_back(abs(B[i] - B[i - 1]));
		a.push_back(abs(1 - B[i - 1]));
		a.push_back(abs(B[i] - 1));
		a.push_back(1 - 1);

		S.push_back(a);
	}

	//for (int i{ 0 }; i < size_ - 1; i++)
	//{
	//	for (int j{ 0 }; j < 4; j++)
	//	{
	//		cout << S[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	Aux left{};
	Aux Right{};

	left.value = S[0][0] > S[0][2] ? S[0][0] : S[0][2];
	left.index = S[0][0] > S[0][2] ? 0 : 2;

	Right.value = S[0][1] > S[0][3] ? S[0][1] : S[0][3];
	Right.index = S[0][1] > S[0][3] ? 1 : 3;
	

	for (int i{ 1 }; i < size_ - 1; i++)
	{
		if (left.index % 2 == 0)
		{
			left.value = left.value + (S[i][0] > S[i][1] ? S[i][0] : S[i][1]);
			left.index = (S[i][0] > S[i][1] ? 0 : 1);
		}
		else
		{
			left.value = left.value + (S[i][2] > S[i][3] ? S[i][2] : S[i][3]);
			left.index = (S[i][2] > S[i][3] ? 2 : 3);
		}

		if (Right.index % 2 == 0)
		{
			Right.value = Right.value + (S[i][0] > S[i][1] ? S[i][0] : S[i][1]);
			Right.index = (S[i][0] > S[i][1] ? 0 : 1);
		}
		else
		{
			Right.value = Right.value + (S[i][2] > S[i][3] ? S[i][2] : S[i][3]);
			Right.index = (S[i][2] > S[i][3] ? 2 : 3);
		}
	}

	cost_ = (left.value > Right.value) ? left.value :Right.value;

	return cost_;
}



int cost2(const vector<int>& B)
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
	vector<int> B{ 52, 60, 50, 90, 84, 35, 56, 64, 52, 20, 43, 19, 12, 73, 48, 93, 43, 78, 22, 53, 60, 100, 26, 54, 84 };
	cout << cost(B);
	return 0;
}