#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

vector<pair<int, int> > v[10001];
int dis[10001];
int dis2[10001];
void dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));
    dis[start] = 0;
    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (distance > dis[current])
            continue;
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextDis = distance + v[current][i].second;
            if (nextDis < dis[next])
            {
                dis[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
}
void dijkstra2(int start)
{
    dis2[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));
    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (distance > dis2[current])
            continue;
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextDis = distance + v[current][i].second;
            if (nextDis < dis2[next])
            {
                dis2[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
}

int main(void)
{
    int N, M, X;
    int maxi = 0;
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++)
    {
        dis[i] = 10000;
        dis2[i] = 10000;
    }

    for (int i = 1; i <= M; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        v[temp1].push_back(make_pair(temp2, temp3));
    }

    dijkstra(X);

    for (int i = 1; i <= N; i++)
    {
        if (i != X)
        {
            dijkstra2(i);
            if (dis2[X] + dis[i] > maxi)
            {
                maxi = dis2[X] + dis[i];
            }
            memset(dis2, 10000, sizeof(dis2));
        }
    }
    cout << maxi << endl;

    return 0;
}
