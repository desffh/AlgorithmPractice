#include <iostream>
#define SIZE 5
using namespace std;

int list[SIZE] = { 3,8,7,9,5 };

void Bubble()
{
	// 1. 바깥쪽: 배열 사이즈 만큼 반복 
	for (int i = 0; i < SIZE - 1; i++)
	{
		// 2. 안쪽: 숫자 비교 후 교환 횟수
		// SIZE -i - 1 (-1은 마지막 비교 횟수는 한번이기때문
		for (int j = 0; j < (SIZE - i) - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
			else //j < j + 1 이면 유지
			{
				continue;
			}
		}

	}
	for (const int& element : list)
	{
		cout << element << " ";
	}
}



int main()
{
	// 버블정렬:
	//			제일 처음 인덱스의 값과 다음 인덱스의 값을 비교하여
	//			정렬하는 방식 
	Bubble();

	return 0;
}