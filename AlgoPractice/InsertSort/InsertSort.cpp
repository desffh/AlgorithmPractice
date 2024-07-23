#include <iostream>
#define SIZE 5

using namespace std;

int list[SIZE] = { 12,10, 1, 7, 5 };

int key = 0;
int j = 0;

void Insert()
{
	// 맨 앞의 index는 이미 정렬된 것으로 취급
	for (int i = 1; i < SIZE; i++)
	{
		key = list[i];

		for (int j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j]; // 복사해서 넣어둠
		}

		list[j] = key;
	}

	for (const int& element : list)
	{
		cout << element << " ";
	}
}

int main()
{
	// 삽입 정렬:
	//			 데이터를 하나씩 확인하여 이미 정렬된 부분과
	//			 비교하여 자신의 위치를 찾아 삽입
	Insert();

	return 0;
}