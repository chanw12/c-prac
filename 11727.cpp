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
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n;
    cin >> n;

    int Dp[1001];
    Dp[1] = 1;
    Dp[2] = 3;
    Dp[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        Dp[i] = (Dp[i - 1] + Dp[i - 2] * 2) % 10007;
    }
    cout << Dp[n] << endl;
}