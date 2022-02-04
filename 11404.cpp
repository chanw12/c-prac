#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define INF 10000000;
int arr[101][101];
int dist[101][101];
int town_num;
int bus_num;

struct node
{
    int end;
    int dis;
};

void floid()
{
    for (int i = 1; i <= town_num; i++)
    {
        for (int j = 1; j <= town_num; j++)
        {
            if (i == j)
            {
                continue;
            }
            dist[i][j] = arr[i][j];
        }
    }

    for (int k = 1; k <= town_num; k++)
    {
        for (int i = 1; i <= town_num; i++)
        {
            for (int j = 1; j <= town_num; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= town_num; i++)
    {
        for (int j = 1; j <= town_num; j++)
        {
            if (dist[i][j] == 10000000)
                dist[i][j] = 0;
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main(void)
{

    cin >> town_num;

    cin >> bus_num;

    for (int i = 1; i <= town_num; i++)
    {
        for (int j = 1; j <= town_num; j++)
        {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < bus_num; i++)
    {
        int start, end, dis;
        cin >> start >> end >> dis;
        if (arr[start][end] > dis)
            arr[start][end] = dis;
    }
    floid();

    return 0;
}