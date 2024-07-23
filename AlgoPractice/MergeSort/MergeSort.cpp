#include <iostream>
#define SIZE 8

using namespace std;

// 병합
void Merge(int list[], int start, int middle, int end)
{
	int count = 0; // 임시배열 가리킴
	int left = start; // 왼쪽 배열
	int right = middle + 1; // 오른쪽 배열

	int* temporary = new int[end - start + 1]; // 배열 크기가 2

	// 1. 배열의 값 비교 후 임시배열에 정렬
	while (left <= middle && right <= end)
	{
		// 두 부분 배열 중 하나라도 끝까지 다루지 않은 동안 반복
		if (list[left] >= list[right])
		{
			// temporary 처음은[0] count, right 모두 후위증가
			temporary[count++] = list[right++];
		}
		else // left <= right
		{
			temporary[count++] = list[left++];
		}
	}
	// 2. 남은 요소 복사
	while (left <= middle)
	{
		temporary[count++] = list[left++];
	}
	while (right <= end)
	{
		temporary[count++] = list[right++];
	}

	// 3. 임시 배열에 있는 값 기존 배열에 복사
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = temporary[i];
	}

	delete temporary;
}

// 분할
void MergeSort(int list[], int start, int end)
{
	// 나눌 기점
	int middle = (start + end) / 2;

	if (start < end)
	{
		MergeSort(list, start, middle); // left 부분
		MergeSort(list, middle + 1, end); // right 부분
		Merge(list, start, middle, end);
	}
}



int main()
{
#pragma region 병합정렬
	// 요소를 1이 될때까지 반으로 나누고,
	// 다시 배열을 정렬 한 다음 병합
	// 분할(Divide)->정복(Conquer)->병합(Combine)

	int list[SIZE] = { 3,5,2,7,4,1,8,6 };

	// MergeSort(int list[], start, end);
	MergeSort(list, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] << " ";
	}

#pragma endregion


	return 0;
}