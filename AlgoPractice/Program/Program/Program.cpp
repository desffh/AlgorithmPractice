#include <iostream>
using namespace std;

// 유클리드 호제법
// 두 개의 자연 수의 최대공약수를 구하는 알고리즘

// 최대공약수 : 두 개의 공통된 약수 중 가장 큰 약수

// 큰수에서 작은수를 나눈 나머지값으로 계속 나누는 방식

int Euclidean(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return Euclidean(y, x % y);
	}

}

int main()
{
	cout << Euclidean(48, 18);

	return 0;
}