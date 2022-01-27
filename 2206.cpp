

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stack>
using namespace std;

string arr[1001];
int visited[1001][1001][2];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int n, m;

struct pos
{
    int x;
    int y;
    int block;
};
int bfs()
{
    queue<pos> s;
    pos t = {0, 0, 1};
    s.push(t);
    visited[0][0][1] = 1;
    while (!s.empty())
    {

        pos current;
        current = s.front();
        s.pop();

        if (n - 1 == current.x && m - 1 == current.y)
        {
            return visited[current.x][current.y][current.block];
        }
        for (int i = 0; i < 4; i++)
        {
            int nextx = current.x + x[i];
            int nexty = current.y + y[i];
            if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m)
            {
                if (arr[nextx][nexty] == '1' && current.block)
                {

                    pos temp = {nextx, nexty, current.block - 1};
                    s.push(temp);
                    visited[nextx][nexty][current.block - 1] = visited[current.x][current.y][current.block] + 1;
                }
                else if (arr[nextx][nexty] == '0' && visited[nextx][nexty][current.block] == 0)
                {
                    pos temp = {nextx, nexty, current.block};
                    s.push(temp);
                    visited[nextx][nexty][current.block] = visited[current.x][current.y][current.block] + 1;
                }
            }
        }
    }
    return -1;
}
int main(void)
{

    cin >> n >> m;
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << bfs() << endl;

    return 0;
}
