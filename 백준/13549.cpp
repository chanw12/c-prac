#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;
int dis[222222];
int n, k;
void solve(int start)
{
    deque<int> dq;
    dq.push_front(start);
    dis[start] = 0;
    while (!dq.empty())
    {
        int current = dq.front();
        dq.pop_front();
        if (current == k)
            return;
        int next = current + 1;
        int nextDis = dis[current] + 1;
        if (next < 100001 && dis[next] > nextDis)
        {
            dq.push_back(next);
            dis[next] = nextDis;
        }
        next = current - 1;
        if (next > -1 && dis[next] > nextDis)
        {
            dq.push_back(next);
            dis[next] = nextDis;
        }
        next = current * 2;
        nextDis = dis[current];
        if (next < 222222 && dis[next] > dis[current])
        {
            dq.push_front(next);
            dis[next] = dis[current];
        }
    }
}

int main(void)
{

    cin >> n >> k;
    fill(dis, dis + 211111, 100000);
    solve(n);
    cout << dis[k] << endl;
}