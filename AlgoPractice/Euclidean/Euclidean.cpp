#include <iostream>
using namespace std;

// 유클리드 호제법

// 큰수 int x;
// 작은수 int y;

//1. x % y = 몫 --- 나머지 y1

//2. y % 나머지 y1 = 몫 --- 나머지 y2

//3. y1 % y2 = 몫 --- 나머지 y3

//4. y2 % y3 = 몫 --- 나머지 0
//		x    y
//최종: y3 % 0 = 일때 y는 0, 최대공약수인 x를 반환

// 나머지가 0일때의 y값이 최대공약수
// y3 = 최대공약수

int Euclid(int x, int y)
{
	// 더이상 나누어 떨어지지 않음 y = 최대공약수
	if (y == 0)
	{
		return x;
	}
	else
	{
		return Euclid(y, x % y);
	}
}


int main()
{
	int x = 12300;
	int y = 55400;

	cout << "두 수의 최대 공약수 :";

	// x,y중 큰 값은 max, 작은 값은 min
	// 서로 위치가 바뀌지 않게 설정됨
	cout << Euclid(max(x, y), min(x, y)) << endl;


	return 0;
}