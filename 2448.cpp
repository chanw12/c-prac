#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n;
string arr[7000];
void printStar(int num, int x, int y)
{
    if (num > 1)
    {
        int temp = 3 * pow(2, num - 2);
        printStar(num - 1, x, y);
        printStar(num - 1, x - temp, y + temp);
        printStar(num - 1, x + temp, y + temp);
    }
    else
    {
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        arr[y + 2][x - 2] = '*';
        arr[y + 2][x - 1] = '*';
        arr[y + 2][x] = '*';
        arr[y + 2][x + 1] = '*';
        arr[y + 2][x + 2] = '*';
    }
}

int main(void)
{

    cin >> n;
    int temp = n / 3;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            arr[i] += " ";
        }
    }
    while (temp >= 1)
    {
        temp = temp / 2;
        k++;
    }

    printStar(k, n - 1, 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}