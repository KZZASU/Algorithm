#include "extralong.h"

void extraLongFactorials(int n)
{
	int* arr = new int[::size];
	for (int i{ 0 }; i < ::size; i++)
	{
		arr[i] = 0;
	}
	arr[::size-1] = 1;
	if (n == 0)
	{
		printFactorial(arr);
		return;
	}

	for (int j{ 1 }; j < n+1; j++)
	{
		carrySum(arr, j);
	}

	printFactorial(arr);
	// for printing the number;
}

void carrySum(int* arr, int count)
{
	int* add = new int[::size];
	for (int i{ 0 }; i < ::size; i++)
	{
		add[i] = arr[i];
	}

	while (count > 1)
	{
		for (int j{ ::size - 1 }; j > 0; j--)
		{
			int temp = arr[j] + add[j];
			if (temp >= 10)
			{
				arr[j - 1] += 1;
				arr[j] = temp - 10;
			}
			else
			{
				arr[j] = temp;
			}
		}
		count--;
	}

}

void printFactorial(int arr[])
{
	int j = 0;
	while (arr[j] == 0)
	{
		j++;
	}

	for (j; j < ::size; j++)
	{
		std::cout << arr[j];
	}


}