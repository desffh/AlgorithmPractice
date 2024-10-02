#include <iostream>
using namespace std;

// 탐욕법
// -> 최적의 해를 구하는데 사용되는 방식
// -> "그 순간에" 최적이라고 생각되는 것을 선택해나감
// -> 단순해서 실행시간이 빠름

int Greedy(int n)
{
	int count = 0;

	while (n != 0)
	{
		if (n >= 1000)
		{
			n -= 1000;
			count++;
		}
	    else if (n >= 500)
		{
			n -= 500;
			count++;
		}
		else if (n >= 100)
		{
			n -= 100;
			count++;
		}
		else if (n >= 50)
		{
			n -= 50;
			count++;
		}
		else if (n >= 10)
		{
			n -= 10;
			count++;
		}
		else
		{
			break;
		}
	}
	return count;

}



int main()
{
	cout << Greedy(1340);
	// 결과값: 1000 1개, 100 3개, 10 4개


	return 0;
}