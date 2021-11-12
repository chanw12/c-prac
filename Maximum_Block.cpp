#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector< vector<int> > map(n, vector<int>(n));
	vector<int> forward(n);
	vector<int> right(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> forward[i];
	}
	for (int j = 0; j < n; j++)
	{
		cin >> right[j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[j][i] = forward[i];
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j]>right[i])
				map[i][j] = right[i];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += map[i][j];
		}
	}
	cout << sum << endl;

	return 0;
}

