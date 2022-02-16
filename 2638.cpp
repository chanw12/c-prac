#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;
int arr[101][101];
int n, m;
int checking[101][101];
int cnt[101][101];
bool visited[101][101];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

void check(int a, int b)
{
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        arr[current.first][current.second] = 2;
        for (int i = 0; i < 4; i++)
        {
            int nexty = current.first + y[i];
            int nextx = current.second + x[i];
            if (nextx >= 0 && nextx <= m && nexty >= 0 && nexty <= n && !visited[nexty][nextx] && arr[nexty][nextx] != 1)
            {
                visited[nexty][nextx] = true;
                q.push(make_pair(nexty, nextx));
            }
        }
    }
}
void del(int a, int b)
{

    if (visited[a][b] == true)
        return;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nexty = current.first + y[i];
            int nextx = current.second + x[i];
            if (nextx >= 0 && nextx <= m && nexty >= 0 && nexty <= n && !visited[nexty][nextx] && arr[nexty][nextx] == 1)
            {
                visited[nexty][nextx] = true;
                q.push(make_pair(nexty, nextx));
            }
            else if (nextx >= 0 && nextx <= m && nexty >= 0 && nexty <= n && arr[nexty][nextx] == 2)
            {
                checking[current.first][current.second]++;
            }
        }
    }
}
bool isEmpty()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
void init_visited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
}
void init_checking()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            checking[i][j] = 0;
        }
    }
}

int main(void)
{
    int num = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (!isEmpty())
    {
        check(0, 0);
        init_visited();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    del(i, j);
                }
            }
        }
        init_visited();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (checking[i][j] >= 2)
                    arr[i][j] = 2;
            }
        }
        init_checking();

        num++;
    }

    cout << num << endl;
}
