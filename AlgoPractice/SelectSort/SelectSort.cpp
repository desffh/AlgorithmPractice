#include <iostream>
#define SIZE 5
using namespace std;

int list[SIZE] = { 2,5, 7, 1, 3 };

void Select()
{	// 바깥쪽 for문 : 한 요소씩 선택해 최소값 찾아나감
	for (int i = 0; i < SIZE; i++)
	{
		int min = list[i]; // 계속 갱신

		int select = i; // min이 저장된 index값

		// 안쪽 for문 : 선택된 요소를 제외한 이후의 요소 중 최소값 찾아감
		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > list[j])
			{
				// 갱신 
				min = list[j];
				select = j;
			}
		}
		// 갱신 다 하고 난 뒤 swap
		swap(list[i], list[select]); // 최소값 위치 바꾸기
	}
	for (const int& element : list)
	{
		cout << element << " ";
	}
}



int main()
{
	// 선택정렬:
	//			주어진 리스트 내에서 최솟값을 찾아 맨 앞에
	//			위치한 결과를 교체하는 방식

	Select();

	return 0;
}