#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//returns minimum difference btw max with min for the value in the sub_arr of v with size of k 
int maxMin(int k, vector<int> v)
{
	sort(v.begin(), v.end());
	int unfair{ INT_MAX };
	int i{ 0 };
	while (i < static_cast<int>(v.size()) - k+1)
	{
		int new_unfair = v[i + k-1] - v[i];
		if (unfair > new_unfair)
		{
			unfair = new_unfair;
		}
		i++;
	}

	return unfair;
}


int main()
{
	vector<int> v2{ 4504, 1520, 5857, 4094, 4157, 3902, 822, 6643, 2422, 7288, 8245, 9948 ,2822 ,1784 ,7802 ,3142 ,9739 };
	cout << maxMin(5, v2) << '\n';
	return 0;
}