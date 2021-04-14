#include <vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
using namespace std;

void addpylon(int k, int i, vector<int>& light, bool build)
{
	int build_num{ 1 };
	if (!build) build_num = -1;
	for (int j{ i - k + 1 }; j < i + k; j++)
	{
		if (j >= 0 && j < (int)light.size())
		{
			light[j] += build_num;
		}
	};
}

int check(const vector<int>& v)
{
	int sum{ 0 };
	for (int i{ 0 }; i < (int)v.size(); i++)
	{
		if (v[i] == 0) return -1;
	}
	return sum;
}


int pylons(int k, vector<int> v)
{

	int size_ = static_cast<int>(v.size());
	int num_pylon{ 0 };
	int i{ 0 };
	while (v[i] != 1)
	{
		i++;
	}
	vector<int> light(i + 1);
	addpylon(k, i, light, true);
	num_pylon++;
	if (check(light) == -1) return -1;
	int last_pylon{ i };

	for (int j{ i + 1 }; j < size_; j++)
	{
		addpylon(k, last_pylon, light, false);
		num_pylon--;
		light.push_back(0);
		if (v[j] == 1)
		{
			addpylon(k, j, light, true);
			num_pylon++;
			int c1{ check(light) };
			if (c1 == -1)
			{
				addpylon(k, last_pylon, light, true);
				num_pylon++;
				addpylon(k, j, light, false);
				num_pylon--;
				int c2{ check(light) };
				if (c2 == -1)
				{
					addpylon(k, j, light, true);
					num_pylon++;
					last_pylon = j;
				}
			}
			else
			{
				last_pylon = j;
			}

		}
		else
		{
			addpylon(k, last_pylon, light, true);
			num_pylon++;
		}
	}
	if (check(light) == -1) { return -1; }
	return num_pylon;
}

int main()
{


	HANDLE clip;
	string clip_text = " ";

	if (OpenClipboard(NULL))
	{
		clip = GetClipboardData(CF_TEXT);
		clip_text = static_cast<char*>(clip);
		CloseClipboard();
	}

	vector<int> v{};
	int i{ 0 };
	while (clip_text[i] != '\0')
	{
		if (clip_text[i] != ' ') v.push_back((int)clip_text[i] - 48);
		i++;
	}

	cout << "the result is " <<pylons(20, v) << '\n';
	return 0;
}