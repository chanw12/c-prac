#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        bool check = false;
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int cnt = 1;
        int x = 1, y = 1;
        int ans = abs(a - b);
        while (true)
        {
            if (abs(x - y) != ans)
            {
                if (n - x > m - y)
                {
                    cnt += m - y;
                    x += m - y;
                    y = m;
                }
                else
                {
                    cnt += n - x;
                    y += n - x;
                    x = n;
                }
                if (x == n && y == m)
                    break;
                if (++x > n)
                    x = 1;
                if (++y > m)
                    y = 1;
                cnt++;
            }
            else
            {
                if (x == a && y == b)
                {
                    check = true;
                    break;
                }
                if (++x > n)
                    x = 1;
                if (++y > m)
                    y = 1;
                cnt++;
                        }
        }
        if (check)
        {
            cout << cnt << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}