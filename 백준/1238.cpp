#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;
int maxi;
int maxIndex;
int visited[10001];
int dis[10001];
int visited2[10001];

struct node
{
    int dis;
    int desti;
};
vector<vector<node> > v(10001);
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            node x = v[current][i];
            if (visited[x.desti] == 0)
            {
                q.push(x.desti);
                visited[x.desti] = visited[current] + x.dis;
            }
            else if (visited[x.desti] > visited[current] + x.dis)
            {
                q.push(x.desti);
                visited[x.desti] = visited[current] + x.dis;
            }
        }
    }
}
void bfs2(int start, int end)
{
    queue<int> q;
    q.push(start);
    visited2[start] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            node x = v[current][i];
            if (visited2[x.desti] == 0)
            {
                q.push(x.desti);
                visited2[x.desti] = visited2[current] + x.dis;
            }
            else if (visited2[x.desti] > visited2[current] + x.dis)
            {
                q.push(x.desti);
                visited2[x.desti] = visited2[current] + x.dis;
            }
        }
    }
}

int main(void)
{
    int N, M, X;
    cin >> N >> M >> X;
    for (int i = 1; i <= M; i++)
    {
        node nd;
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        nd.desti = temp2;
        nd.dis = temp3;
        v[temp1].push_back(nd);
    }

    bfs(X);

    for (int i = 1; i <= N; i++)
    {
        bfs2(i, X);
        dis[i] = visited2[X] - 1;
        memset(visited2, 0, sizeof(visited2));
    }
    for (int i = 1; i <= N; i++)
    {
        int sum = visited[i] + dis[i] - 1;
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    cout << maxi << endl;

    return 0;
}
