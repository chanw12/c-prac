#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int maxi = 0;
int maxiIndex = 0;
int visited[100001];
struct node
{
    int vNum, dis;
};

vector<node> vv[100001];
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (maxi < visited[current])
        {
            maxi = visited[current];
            maxiIndex = current;
        }

        for (int i = 0; i < vv[current].size(); i++)
        {
            int y = vv[current][i].vNum;
            if (visited[y] == 0)
            {
                q.push(y);
                visited[y] = visited[current] + vv[current][i].dis;
            }
        }
    }
}
int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int number;
        cin >> number;
        vector<node> v;
        while (true)
        {
            int vNum, dis;
            cin >> vNum;
            if (vNum == -1)
                break;
            cin >> dis;
            node nd;
            nd.vNum = vNum;
            nd.dis = dis;
            v.push_back(nd);
        }
        vv[number] = v;
    }

    bfs(1);
    memset(visited, 0, sizeof(visited));
    maxi = 0;
    bfs(maxiIndex);
    cout << maxi - 1 << endl;

    return 0;
}