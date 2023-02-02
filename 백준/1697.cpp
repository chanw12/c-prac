#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>

using namespace std;

int bfs(int start,int target)
{
	vector<int> v(1000012);
	queue<int> q;
	q.push(start);
	v[start] = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int next;
			if (i == 0)
				next = current - 1;
			else if (i == 1)
				next = current + 1;
			else
				next = current * 2;
			if (next < 0 || next > 100000)
				continue;
			if (next == target)
				return v[current] + 1;
			if (!v[next])
			{
				v[next] = v[current] + 1;
				q.push(next);
			}
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	if (N == K)
	{
		cout << 0 << endl;
		return 0;
	}

	int k = bfs(N, K);
	cout << k << endl;
	
	return 0;
}

