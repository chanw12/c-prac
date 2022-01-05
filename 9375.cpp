#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        map<string, int> m;
        int sum = 1;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {

            string name, kind;
            cin >> name >> kind;

            if (m.find(kind) != m.end())
            {
                m[kind]++;
            }
            else
            {
                m.insert(pair<string, int>(kind, 1));
            }
        }
        map<string, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            sum *= iter->second + 1;
        }
        cout << sum - 1 << endl;
    }
}