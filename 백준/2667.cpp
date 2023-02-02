#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int cnt;
string map[30];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
bool visited[30][30];
int apart[10000000];

void bfs(int startx, int starty)
{
    queue<pair<int, int> > q;

    if (visited[startx][starty] == false && map[startx][starty] == '1')
    {
        q.push(make_pair(startx, starty));
        visited[startx][starty] = true;
        cnt++;
        apart[cnt]++;
    }

    while (!q.empty())
    {
        pair<int, int> k = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (k.first + x[i] >= 0 && k.second + y[i] >= 0)
            {
                if (map[k.first + x[i]][k.second + y[i]] == '1')
                {
                    if (visited[k.first + x[i]][k.second + y[i]] == false)
                    {
                        q.push(make_pair(k.first + x[i], k.second + y[i]));
                        visited[k.first + x[i]][k.second + y[i]] = true;
                        apart[cnt]++;
                    }
                }
            }
        }
    }
}

int main(void)
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> map[i];
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            bfs(i, j);
        }
    }
    cout << cnt << endl;
    sort(apart + 1, apart + cnt + 1);
    for (int i = 1; i <= cnt; i++)
    {
        cout << apart[i] << endl;
    }
}