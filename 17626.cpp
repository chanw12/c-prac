#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int Dp[50001];
    for (int i = 0; i < 50001; i++)
    {
        Dp[i] = 10000;
    }
    for (int i = 1; i < 225; i++)
    {
        Dp[i * i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            Dp[i] = min(Dp[i], Dp[j * j] + Dp[i - j * j]);
        }
    }
    cout << Dp[n] << endl;
}