#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <map>
using namespace std;
#define INF 100000000
int dis[501];
int N, M, W;
struct Edge
{
    int s, e, t;
};

void bellmanFord(vector<Edge> ed, int start)
{
    dis[start] = 0;
    int s, e, t;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < ed.size(); j++)
        {
            s = ed[j].s;
            e = ed[j].e;
            t = ed[j].t;
            if (i == N)
            {

                if (dis[e] > dis[s] + t)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            else
            {
                if (dis[e] > dis[s] + t)
                {
                    dis[e] = dis[s] + t;
                }
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main(void)
{

    int TC;
    cin >> TC;

    for (int t = 0; t < TC; t++)
    {
        vector<Edge> ed;
        cin >> N >> M >> W;
        for (int i = 0; i < M; i++)
        {
            Edge ev;
            int s, e, t;
            cin >> s >> e >> t;
            ev.s = s;
            ev.e = e;
            ev.t = t;
            ed.push_back(ev);
            ev.s = e;
            ev.e = s;
            ed.push_back(ev);
        }
        for (int i = 0; i < W; i++)
        {
            Edge ev;
            int s, e, t;
            cin >> s >> e >> t;
            ev.s = s;
            ev.e = e;
            ev.t = -t;
            ed.push_back(ev);
        }
        for (int i = 1; i <= N; i++)
        {
            dis[i] = INF;
        }

        bellmanFord(ed, 1);
    }

    return 0;
}
