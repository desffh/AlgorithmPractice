#include <iostream>
using namespace std;
#define SIZE 8

// 병합하기
void Merge(int list[], int start, int middle, int end)
{
	// 정렬된 거 담을 동적배열 생성
	int* temporary = new int[end - start + 1];
	int count = 0; // 배열의 크기

	int left = start;
	int right = middle + 1;

	// 병합하기
	while (left <= middle && right <= end)
	{
		// left<>right 비교
		if (list[left] <= list[right])
		{
			temporary[count++] = list[left++];
		}
		else
		{
			temporary[count++] = list[right++];
		}
	}

	// 남은 배열의 요소들을 복사
	while (left <= middle)
	{
		temporary[count++] = list[left++];
	}
	while (right <= end)
	{
		temporary[count++] = list[right++];
	}

	// 임시배열에 저장된 값을 원본배열로 복사 
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = temporary[i];
	}
	// 동적배열 해제
	delete temporary;

}

// 분할하기(Divide)
void MergeSort(int list[], int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2; // 중간값

		// 재귀함수를 사용해 가장 작은 단위까지 분할
		MergeSort(list, start, middle);
		MergeSort(list, middle + 1, end);

		Merge(list, start, middle, end);
	}
}

int main()
{
	// 병합정렬 (Merge Sort)
	// 1. 분할: 가장 작은 단위까지 분할
	// 2. 정렬: 가장 작은 단위부터 정렬
	int list[SIZE] = { 3, 5, 2, 7, 4, 1, 8, 6 };

	MergeSort(list, 0, SIZE - 1);

	for (const int element : list)
	{
		cout << element << " ";
	}

	return 0;
}