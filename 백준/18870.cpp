#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> a = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]] = i;
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << m[a[i]] << " ";
    }
    cout << "\n";

    return 0;
}