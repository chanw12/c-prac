#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <map>
using namespace std;
#define INF 100000000
int dis[1001];
vector<pair<int, int> > v[100001];
int N, M;

void dijkstra(int start)
{

    dis[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (dis[current] < distance)
            continue;
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].second;
            int nextDis = v[current][i].first + distance;

            if (nextDis < dis[next])
            {
                dis[next] = nextDis;
                pq.push(make_pair(-nextDis, next));
            }
        }
    }
}

int main(void)
{

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        v[s].push_back(make_pair(t, e));
    }
    int start, end;
    cin >> start >> end;
    for (int i = 1; i <= N; i++)
    {
        dis[i] = INF;
    }
    dijkstra(start);
    cout << dis[end] << endl;
}
