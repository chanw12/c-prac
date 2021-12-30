#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int arr[501][501];
bool visited[501][501];
int maxValue;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int n, m;

void dfs(int c, int d, int cnt, int sum)
{
    visited[c][d] = true;
    if (cnt == 3)
    {
        maxValue = max(maxValue, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int a = c + x[i];
        int b = d + y[i];

        if (a < 0 || b < 0 || a >= n || b >= m)
            continue;
        if (visited[a][b] == true)
            continue;
        dfs(a, b, cnt + 1, sum + arr[a][b]);
        visited[a][b] = false; // 방문한 지점을 여러번 방문하여 카운트를 할수 있기 때문에 계산이 끝난후에 visited를 false로 바꿔야한다.
    }
}
void First_shape(int x, int y)
{
    int Tmp_Sum = 0;
    Tmp_Sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 1];
    if (Tmp_Sum > maxValue)
        maxValue = Tmp_Sum;
}

void Second_shape(int x, int y)
{
    int Tmp_Sum = 0;
    Tmp_Sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1];
    if (Tmp_Sum > maxValue)
        maxValue = Tmp_Sum;
}

void Third_shape(int x, int y)
{
    int Tmp_Sum = 0;
    Tmp_Sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y + 1];
    if (Tmp_Sum > maxValue)
        maxValue = Tmp_Sum;
}

void Last_shape(int x, int y)
{
    int Tmp_Sum = 0;
    Tmp_Sum = arr[x][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1];
    if (Tmp_Sum > maxValue)
        maxValue = Tmp_Sum;
}

int main()
{
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(visited, false, sizeof(visited));
            dfs(i, j, 0, arr[i][j]);
            if (i - 1 >= 0 && j + 2 < m)
                First_shape(i, j);
            if (j + 2 < m && i + 1 < n)
                Second_shape(i, j);
            if (i + 2 < n && j + 1 < m)
                Third_shape(i, j);
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m)
                Last_shape(i, j);
        }
    }
    cout << maxValue << endl;
}