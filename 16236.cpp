#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[21][21];
queue<pair<int, int> > q;
int visited[21][21];
int sizekk = 2;
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
int minValue = 10000;
int min_x;
int min_y;
int n;
int cnt = 0;
void bfs(int a, int b)
{
    q.push(make_pair(a, b));
    arr[a][b] = 0;
    visited[a][b] = 1;
    while (!q.empty())
    {
        pair<int, int> p;
        p = q.front();
        q.pop();

        if (arr[p.first][p.second] < sizekk && arr[p.first][p.second] > 0)
        {
            if (visited[p.first][p.second] - 1 < minValue)
            {
                minValue = visited[p.first][p.second] - 1;
                min_x = p.first;
                min_y = p.second;
            }
            else if (visited[p.first][p.second] - 1 == minValue)
            {
                if (min_x == p.first)
                {
                    if (min_y > p.second)
                    {
                        min_x = p.first;
                        min_y = p.second;
                    }
                }
                else if (min_x > p.first)
                {
                    min_x = p.first;
                    min_y = p.second;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int c = p.first + x[i];
            int d = p.second + y[i];

            if (c >= 0 && c < n && d >= 0 && d < n)
            {
                if (arr[c][d] <= sizekk && visited[c][d] == 0)
                {
                    q.push(make_pair(c, d));
                    visited[c][d] = visited[p.first][p.second] + 1;
                }
            }
        }
    }
}
void init_visited()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            visited[i][j] = 0;
        }
    }
    minValue = 10000;
    min_x = 10000;
    min_y = 10000;
}
int main(void)
{

    int sum = 0;
    int startx = 0;
    int starty = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                startx = i;
                starty = j;
            }
        }
    }
    while (true)
    {
        init_visited();
        bfs(startx, starty);
        if (minValue != 10000)
        {
            sum += minValue;
            cnt++;
            if (cnt == sizekk)
            {
                sizekk++;
                cnt = 0;
            }
            arr[min_x][min_y] = 0;
            startx = min_x;
            starty = min_y;
        }
        else
        {
            break;
        }
    }
    cout << sum << endl;

    return 0;
}