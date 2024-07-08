/** 구현 16967 배열 복원하기 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int H, W, X, Y;
int B[700][700];
int A[400][400];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> X >> Y;

    for (int i = 0; i < H + X; i++)
    {
        for (int j = 0; j < W + Y; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            // A[i][j] 채우기
            // i >= X && j >= Y
            // B[i][j] - A[i-X, j-Y] -> A[i][j]
            if (i >= X && j >= Y)
            {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            }
            else
            {
                A[i][j] = B[i][j];
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}
