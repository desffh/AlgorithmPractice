#include <iostream>
using namespace std;
#define SIZE 11

// 쉘 정렬 (Shell Sort)
// 삽입정렬과 비슷하지만 더 빠름

// 삽입정렬은 앞의 배열과 비교하여 자신이 들어갈 위치를 정하는데,
// 정렬이 되어있지않고 멀다면 시간이 오래걸림

// 조금이라도 정렬된 상태에서 삽입정렬을 수행하는 방법

int list[SIZE] = { 10,50,40,20,60, 45,35,15,95,25, 14 };

void ShellSort()
{
	int gap = 0; // 초기 간격

	int j = 0;
	int key = 0; // 현재 정렬하고 있는 요소

	// 간격 계속 /2
	for (gap = SIZE / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
		{
			gap++; // 간격 홀수로 (마지막 gap이 홀수(1)가 되게 하기 위해)
		}

		for (int i = gap; i < SIZE; i++)
		{
			key = list[i];

			for (j = i; j >= gap && list[j - gap] > key; j -= gap)
			{
				list[j] = list[j - gap];
			}
			list[j] = key;
		}
	}

	for (const int& element : list)
	{
		cout << element << " ";
	}
}


int main()
{
	ShellSort();

	return 0;
}