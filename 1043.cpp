#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int get_parent(int arr[], int x)
{
    if (arr[x] == x)
        return x;
    else
        return arr[x] = get_parent(arr, arr[x]);
}

void unionParent(int arr[], int x, int y)
{
    x = get_parent(arr, x);
    y = get_parent(arr, y);
    arr[y] = x;
}

bool find_same_parent(int arr[], int x, int y)
{
    x = get_parent(arr, x);
    y = get_parent(arr, y);
    if (x == y)
        return true;
    else
        return false;
}

int main(void)
{
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n, m, k; // n은 총 사람의수 m은 파티의수 k는 진실을 아는 사람의수
    int know_person[51];
    vector<vector<int> > v;
    int parent[51];
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> know_person[i];
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vector<int> v1;
        for (int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }
        v.push_back(v1);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            unionParent(parent, v[i][0], v[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        bool check = false;
        for (int j = 0; j < k; j++)
        {
            if (find_same_parent(parent, v[i][0], know_person[j]))
            {
                check = true;
                break;
            }
        }
        if (!check)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}