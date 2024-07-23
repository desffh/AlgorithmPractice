#include <iostream>

using namespace std;

int Money(int n)
{
	int count = 0;

	while (n != 0)
	{
		if (n >= 1000)
		{
			n = n - 1000;
			count++;
		}
		else if (n >= 500)
		{
			n = n - 500;
			count++;
		}
		else if (n >= 100)
		{
			n = n - 100;
			count++;
		}
		else if (n >= 50)
		{
			n = n - 50;
			count++;
		}
		else if (n >= 10)
		{
			n = n - 10;
			count++;
		}
	}
	return count;
}


int main()
{
	// Greedy탐욕법

	// 거스름돈 반환

	int money = 1430;

	cout << Money(money) << endl;

	return 0;
}