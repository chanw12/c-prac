#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;


int main() {
	int num;
	cin >> num;
	for (int j = 0; j < num; j++)
	{
		int N, M;
		cin >> N >> M;
		int i = 1;
		if (N > M - N) N = M - N;// ncr = ncn-r
		long long result = 1;
		while (i != N + 1)
		{
			result *= M--;
			result /= i++;
		}
		cout << result << '\n';
	}
    return 0;
}
