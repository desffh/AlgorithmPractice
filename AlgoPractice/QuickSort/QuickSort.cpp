#include <iostream>
using namespace std;
#define SIZE 9


void QuickSort(int list[], int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int pivot = start; // 기준점

	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && list[pivot] >= list[left])
		{
			left++; // left가 기준점보다 작으면 left를 계속++하여 큰값을 찾아감 
		}
		while (right > start && list[pivot] <= list[right])
		{
			right--; // right가 기준점보다 크면 right를 계속--하여 작은값을 찾아감
		}
		if (left > right) // 서로 엇갈림 
		{
			std::swap(list[pivot], list[right]);
		}
		else // 값을 찾고 서로 swap
		{
			std::swap(list[left], list[right]);
		}
	}
	// 재귀적으로 호출하여 중간값이 right를 기준으로 다시 정렬
	QuickSort(list, start, right - 1);
	QuickSort(list, right + 1, end);
}


int main()
{
	// 퀵 정렬(Quick Sort)
	// 기준값을 정해서 기준값보다 작으면 왼쪽, 크면 오른쪽으로 정렬해나가는 방식

	int list[SIZE] = { 5,9,6,2,1,3,4,7,8 };

	QuickSort(list, 0, SIZE - 1);

	for (const int element : list)
	{
		cout << element << " ";
	}

}