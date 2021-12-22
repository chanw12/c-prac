#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int a, b;
bool visited[10000];
string bfs()
{
    queue<pair<string, int> > q;
    q.push(make_pair("", a));
    visited[a] = true;
    while (!q.empty())
    {
        int num = q.front().second;
        string change = q.front().first;
        q.pop();

        if (num == b)
            return change;

        // D
        int newValue = (num * 2) % 10000;
        if (!visited[newValue])
        {
            visited[newValue] = true;
            q.push(make_pair(change + "D", newValue));
        }
        // S
        newValue = (num - 1) < 0 ? 9999 : num - 1;
        if (!visited[newValue])
        {
            visited[newValue] = true;
            q.push(make_pair(change + "S", newValue));
        }
        // L
        int c = num / 1000;
        newValue = (num * 10 + c) - (num / 1000 * 10000);
        if (!visited[newValue])
        {
            visited[newValue] = true;
            q.push(make_pair(change + "L", newValue));
        }
        // R
        c = num % 10;
        newValue = (num / 10) + (c * 1000);
        if (!visited[newValue])
        {
            visited[newValue] = true;
            q.push(make_pair(change + "R", newValue));
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
    for (int i = 0; i < n; i++)
    {
        memset(visited, false, sizeof(visited));
        cin >> a >> b;
        string result = bfs();
        cout << result << endl;
    }
    return 0;
}