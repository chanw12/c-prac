#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
char arr[101][101];
queue<pair<int, int> > q;
queue<pair<int, int> > qq;
bool visited[101][101];
bool visitedRG[101][101];
int bfs(int a, int b)
{
    if (visited[a][b])
        return 0;
    char check = arr[a][b];

    visited[a][b] = true;
    q.push(make_pair(a, b));
    pair<int, int> p;
    while (!q.empty())
    {
        p.first = q.front().first;
        p.second = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int c = p.first + x[i];
            int w = p.second + y[i];
            if (arr[c][w] == check && !visited[c][w])
            {
                q.push(make_pair(c, w));
                visited[c][w] = true;
            }
        }
    }
    return 1;
}

int bfs_forRG(int a, int b)
{
    if (visitedRG[a][b])
        return 0;
    char check = arr[a][b];

    if (check == 'G')
        check = 'R';
    visitedRG[a][b] = true;
    qq.push(make_pair(a, b));
    pair<int, int> p;
    while (!qq.empty())
    {
        p.first = qq.front().first;
        p.second = qq.front().second;
        qq.pop();
        for (int i = 0; i < 4; i++)
        {
            int c = p.first + x[i];
            int w = p.second + y[i];
            if (arr[c][w] == 'G')
                arr[c][w] = 'R';
            if (arr[c][w] == check && !visitedRG[c][w])
            {
                qq.push(make_pair(c, w));
                visitedRG[c][w] = true;
            }
        }
    }
    return 1;
}
int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int cnt1 = 0;
    int cnt2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt1 += bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt2 += bfs_forRG(i, j);
        }
    }
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    return 0;
}
