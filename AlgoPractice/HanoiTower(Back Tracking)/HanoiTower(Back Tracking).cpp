#include <iostream>

using namespace std;

// 하노이의 탑 (A->C 기둥으로 원판 모두 옮기기)

// n :원판의 갯수
// start : 맨 처음 위치의 기둥
// middle : 보조 기둥
// end : 최종 도착 위치의 기둥

void HanoiTower(int n, char start, char middle, char end)
{
	// 원판의 갯수가 1개면 start->end로 이동
	if (n == 1)
	{
		cout << "[" << n << "] " << start << "->" << end << endl;
	}
	else
	{
		// 1. 재귀함수를 돌려서 작은 원판들 start->middle로 옮기기
		HanoiTower(n - 1, start, end, middle);
		// 2. 큰 원판을 start->end로 이동
		cout << "[" << n << "] " << start << "->" << end << endl;
		// 3. 재귀함수를 돌려서 작은 원판들 middle->end로 이동
		HanoiTower(n - 1, middle, start, end);
	}
}	// 원판의 갯수가 n-1 재귀가 되면서 1개씩 이동이 가능함


int main()
{
	HanoiTower(3, 'A', 'B', 'C');

	return 0;
}