#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;
#define MAX_INT 2147483647

vector<pair<int, int> > v[10001];
int dis[10001];
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
void init_dis()
{
    for (int i = 0; i < 1000; i++)
    {
        dis[i] = MAX_INT;
    }
}

int main(void)
{
    vector<int> arr2;
    vector<int> arr;
    int N, E;
    bool flag = true;
    cin >> N >> E;
    init_dis();
    for (int i = 0; i < E; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        v[temp1].push_back(make_pair(temp2, temp3));
        v[temp2].push_back(make_pair(temp1, temp3));
    }
    int target1, target2;
    cin >> target1 >> target2;
    int sum = MAX_INT;
    dijkstra(1);
    int sTov1 = dis[target1];
    int sTov2 = dis[target2];
    init_dis();

    dijkstra(target1);
    int v1Tov2 = dis[target2];
    int v1Toe = dis[N];
    init_dis();

    dijkstra(target2);
    int v2Tov1 = dis[target1];
    int v2Toe = dis[N];

    sum = min(sum, sTov1 + v1Tov2 + v2Toe);
    sum = min(sum, sTov2 + v2Tov1 + v1Toe);

    if (sum == MAX_INT || v1Tov2 == MAX_INT)
        cout << -1 << endl;
    else
        cout << sum << endl;
    return 0;
}
