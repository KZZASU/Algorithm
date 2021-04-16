#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int trivial(vector<int> price, int length)
{
	int q = 0;

	for (int i{ 0 }; i < length; i++)
	{
		q = max(q,price[i] + trivial(price, length - (i+1)));
	}
	return q;
}

//int main()
//{
//	vector<int> price{ 1,5,8,9,10,17,17,20,24,30 };
//
//	cout << trivial(price, 2) << '\n';
//	return 0;
//}