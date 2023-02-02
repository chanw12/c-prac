#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int calc(long long int a, long long int b, long long int c)
{
    if (b == 0)
        return 1;
    int temp = calc(a, b / 2, c);
    int result = (temp % c * temp % c);
    if (b % 2)
    {
        result = result * a % c;
    }
    return result;
}

int main(void)
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    int result = calc(a, b, c);
    cout << result << endl;
    return 0;
}
