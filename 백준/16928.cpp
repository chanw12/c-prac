#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int visited[101];
map<int, int> ladder;
map<int, int> snake;
int arr[101];
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty())
    {
        int p;
        p = q.front();
        q.pop();
        if (p > 100)
        {
            return;
        }
        map<int, int>::iterator iter;
        iter = ladder.find(p);
        if (iter != ladder.end())
        {
            q.push(ladder[p]);
            visited[ladder[p]] = min(visited[ladder[p]], visited[p]);
            continue;
        }
        iter = snake.find(p);
        if (iter != snake.end())
        {
            q.push(snake[p]);
            visited[snake[p]] = min(visited[snake[p]], visited[p]);
            continue;
        }
        for (int i = 1; i <= 6; i++)
        {
            if (visited[p + i] > visited[p] + 1 && p + i < 101)
            {
                visited[p + i] = min(visited[p + i], visited[p] + 1);
                q.push(p + i);
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        ladder[temp1] = temp2;
    }
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        snake[temp1] = temp2;
    }
    for (int i = 0; i <= 101; i++)
    {
        visited[i] = 10000;
    }
    bfs(1);
    cout << visited[100] << endl;
}