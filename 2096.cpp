

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    int v[3];
    int mini[3] = {0, 0, 0};
    int maxi[3] = {0, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[0] >> v[1] >> v[2];

        int min1, min2, min0, max1, max2, max0;
        min0 = v[0] + min(mini[0], mini[1]);
        min1 = v[1] + min(mini[1], mini[2]);
        min1 = min(v[1] + mini[0], min1);
        min2 = v[2] + min(mini[1], mini[2]);
        max0 = v[0] + max(maxi[0], maxi[1]);
        max1 = v[1] + max(maxi[1], maxi[2]);
        max1 = max(v[1] + maxi[0], max1);
        max2 = v[2] + max(maxi[1], maxi[2]);
        maxi[0] = max0;
        maxi[1] = max1;
        maxi[2] = max2;
        mini[0] = min0;
        mini[1] = min1;
        mini[2] = min2;
    }

    int rst_max = 0, rst_min = 217000000;

    for (int i = 0; i < 3; i++)
    {

        if (rst_max < maxi[i])
            rst_max = maxi[i];
        if (rst_min > mini[i])
            rst_min = mini[i];
    }
    cout << rst_max << " " << rst_min << endl;
    return 0;
}
