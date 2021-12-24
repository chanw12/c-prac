#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int n;
    cin >> n;
    int cnt = 0;
    int arr[100001];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num != 0)
        {
            pq.push(make_pair(abs(num), num));
        }
        else
        {
            int k = 0;
            if (!pq.empty())
            {
                k = pq.top().second;
                pq.pop();
            }
            arr[cnt++] = k;
                }
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}