#include <iostream>
using namespace std;


// 최대공약수
// 두 수가 동시에 나누어 떨어지는 공통된 약수 중 가장 큰 수


int main()
{
	int x = 30;
	int y = 48;

	int num = 0;

	// min(x, y) = x와 y중 더 작은 값을 반환
	for (int i = 1; i <= min(x, y); i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			num = i;
		}
	}
	cout << "최대공약수의 값: " << num << endl;

	return 0;
}