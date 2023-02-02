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
    for (int t = 0; t < n; t++)
    {
        int N;
        cin >> N;
        long long Dp[101];
        Dp[1] = 1;
        Dp[2] = 1;
        Dp[3] = 1;
        Dp[4] = 2;
        Dp[5] = 2;
        Dp[6] = 3;

        for (int i = 7; i <= N; i++)
        {
            Dp[i] = Dp[i - 1] + Dp[i - 5];
        }
        cout << Dp[N] << endl;
    }

    return 0;
}