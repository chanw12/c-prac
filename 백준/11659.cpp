#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int arr[100001];
    int sum[100001];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    int left;
    int right;
    for (int t = 0; t < M; t++)
    {
        cin >> left >> right;
        cout << sum[right] - sum[left - 1] << "\n";
    }
}