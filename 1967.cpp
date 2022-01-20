#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stack>
using namespace std;
vector<pair<int, int> > v[10001];
int visited[10001];
int maxWeight = 0;
void bfs(int start)
{

    stack<int> s;
    s.push(start);
    visited[start] = 1;

    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        if (maxWeight < visited[current])
            maxWeight = visited[current];

        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextWeight = v[current][i].second;

            if (visited[next] == 0)
            {
                s.push(next);
                visited[next] = visited[current] + nextWeight;
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int parentNode, childNode, weight;
        cin >> parentNode >> childNode >> weight;
        v[parentNode].push_back(make_pair(childNode, weight));
        v[childNode].push_back(make_pair(parentNode, weight));
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
        memset(visited, 0, sizeof(visited));
    }
    cout << maxWeight - 1 << endl;
    return 0;
}
