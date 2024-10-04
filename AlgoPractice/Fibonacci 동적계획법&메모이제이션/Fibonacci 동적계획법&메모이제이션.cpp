#include <iostream>
using namespace std;
#define SIZE 1000

// 피보나치 수열

int Fibonacci(int n, int list[])
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n <= 2) // 1,2번째 값은 1
	{
		return 1;
	}

	// 이미 계산된 값이 list에 저장되어있다 (재사용 가능)
	if (list[n] != 0)
	{
		return list[n];
	}

	// 값을 저장
	return list[n] = Fibonacci(n - 1, list) + Fibonacci(n - 2, list);

}



int main()
{
	// 동적계획법
	// -> 특정 범위 값을 구하기 위해서, 다른 범위의 값을 이용해 값을 구하는 효율적인 알고리즘


	// 메모이제이션 기법
	// 동일한 계산을 반복해야할 때, 이전에 계산한 값을 메모리에 저장하여,
	// 동일한 계산을 피하고, 계산속도를 향상시켜주기 위한 기법

	int list[SIZE] = { 0, }; // list 모두 0으로 초기화

	cout << Fibonacci(6, list);

	return 0;
}