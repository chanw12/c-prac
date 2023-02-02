#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        int num;
        cin >> num;
        int arr[2][100001];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[0][i];
        }
        for (int i = 0; i < num; i++)
        {
            cin >> arr[1][i];
        }

        int Dp[2][100001];
        Dp[0][0] = arr[0][0];
        Dp[1][0] = arr[1][0];
        for (int j = 1; j < num; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    Dp[i][j] = max(Dp[i + 1][j - 1], Dp[i + 1][j - 2]) + arr[i][j];
                }
                else
                {
                    Dp[i][j] = max(Dp[i - 1][j - 1], Dp[i - 1][j - 2]) + arr[i][j];
                }
            }
        }

        int maxi = max(Dp[0][num - 1], Dp[1][num - 1]);
        cout << maxi << endl;
    }

    return 0;
}