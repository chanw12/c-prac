#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {
	
	int N, M;
	cin >> N >> M;
	vector <int> tree(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	int left = 0, right = tree[N - 1];

	int mini = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			if(tree[i] > mid)
				sum += tree[i] - mid;
		}
		if (sum >= M)
		{
			left = mid + 1;
			mini = max(mini, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << mini << endl;

	return 0;
}
