#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
int M, N, H;
int x[6] = {-1, 0, 1, 0, 0, 0};
int y[6] = {0, 1, 0, -1, 0, 0};
int h[6] = {0, 0, 0, 0, 1, -1};
int v[101][101][101];
struct value
{
    int m, n, h;
};
queue<value> q;
bool visited[101][101][101];
int bfs()
{
    int day = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            value va = q.front();
            q.pop();
            int row, col, hei;
            for (int i = 0; i < 6; i++)
            {
                row = va.m + x[i];
                col = va.n + y[i];
                hei = va.h + h[i];
                if (row <= M && 0 < row && col <= N && 0 < col && hei <= H && 0 < hei)
                {
                    if (v[row][col][hei] == 0 && !visited[row][col][hei])
                    {
                        v[row][col][hei] = 1;
                        value aa;
                        aa.m = row;
                        aa.n = col;
                        aa.h = hei;
                        q.push(aa);
                        visited[row][col][hei] = true;
                    }
                }
            }
        }
        day++;
    }
    day--;
    return day;
}
int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool check = true;

    cin >> M >> N >> H;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                cin >> v[k][j][i];
                if (v[k][j][i] == 1)
                {
                    value s;
                    s.m = k;
                    s.n = j;
                    s.h = i;
                    q.push(s);
                }
            }
        }
    }
    int day = bfs();
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if (v[k][j][i] == 0)
                {
                    check = false;
                    break;
                }
            }
        }
    }
    if (check)
        cout << day << endl;
    else
        cout << -1 << endl;
    return 0;
}