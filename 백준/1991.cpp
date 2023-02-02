#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <map>
using namespace std;
pair<int, int> arr[27];
int n;
void preorder(int num)
{
    if (num >= n)
        return;
    cout << char(num + 65);
    if (arr[num].first >= 0)
        preorder(arr[num].first);
    if (arr[num].second >= 0)
        preorder(arr[num].second);
}
void inorder(int num)
{
    if (num >= n)
        return;

    if (arr[num].first >= 0)
        inorder(arr[num].first);
    cout << char(num + 65);
    if (arr[num].second >= 0)
        inorder(arr[num].second);
}
void postorder(int num)
{
    if (num >= n)
        return;
    if (arr[num].first >= 0)
        postorder(arr[num].first);
    if (arr[num].second >= 0)
        postorder(arr[num].second);
    cout << char(num + 65);
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        arr[temp1 - 'A'].first = temp2 - 'A';
        arr[temp1 - 'A'].second = temp3 - 'A';
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0;
}
