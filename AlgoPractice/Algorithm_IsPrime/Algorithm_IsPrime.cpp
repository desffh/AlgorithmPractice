#include <iostream>
using namespace std;

// 소수 판별하기
// 소수가 맞다면 true 1 / 소수가 아니라면 false 0

bool Number(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true; // 예외를 제외한 나머지는 소수
}


int main()
{
#pragma region 소수 판별하기
    cout << Number(1); // 소수아님 0
    cout << Number(3); // 소수맞음 1
#pragma endregion


    return 0;
}

