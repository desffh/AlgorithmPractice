#include <iostream>
using namespace std;

int number[101]; // 정적배열 생성

// 소수 판정 함수
void Sieve(int n)
{
	// 1. 배열 초기화
	for (int i = 0; i <= n; i++)
	{
		number[i] = i; // 배열의 인덱스 값과 동일한 값 넣어줌
	}
	// 2. 2 ~ 제곱근n까지 반복 
	for (int i = 2; i <= sqrt(n); i++)
	{
		// 3. j 값은 i의 배수만큼 증가
		for (int j = i * i; j <= n; j += i)
		{
			number[j] = 0;
		}
	}
	// 4. 소수 출력 
	for (int i = 2; i <= n; i++) // 1은 소수x
	{
		if (number[i] != 0)
		{
			cout << number[i] << " ";
		}
	}
}




int main()
{
	// 에라토스테네스의 체
	// 1을 제외한 2 ~ 제곱근n까지 돌며 모든 배수들을 제외하여 소수를 찾는 방법

	// ex) 101까지의 수에서 모든 소수 찾기

	Sieve(50);
	



	return 0;
}
