#include <iostream>

using namespace std;


int main()
{
#pragma region 브루트 포스
    // 모든 경우의 수를 탐색하면서 
    // 결과를 도출하는 알고리즘

    // 비밀번호3자리 찾기 (000 ~999)까지

    // 1. 비밀번호 1차원 배열 만들기
    int Password[] = { 2,4,8 };

    // 시간복잡도: 0(n³)

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (Password[0] == i && Password[1] == j
                    && Password[2] == k)
                {
                    cout << "Open" << endl;
                    cout << i << " " << j << " " << k << " ";
                }
            }
        }
    }

#pragma endregion