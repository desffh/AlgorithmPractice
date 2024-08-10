#include <iostream>
#define SIZE 5
using namespace std;

// 누적합
// ex) array[] = {1,2,3,4,5};
// 출력값 :		1,3,6,10,15

int main()
{
	int array[SIZE] = { 1,2,3,4,5 };

	int save[SIZE] = { 0,0,0,0,0 }; // 누적합 저장할 배열

	// save[] = {1,0,0,0,0};
	save[0] = array[0];

	for (int i = 1; i < SIZE; i++)
	{
		save[i] = array[i] + save[i - 1];
	}
	// save배열 출력
	for (int i = 0; i < SIZE; i++)
	{
		cout << save[i] << " ";
	}


	return 0;
}