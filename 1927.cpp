#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<map>
#include<queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int,vector<int>,greater<int>> pq;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0 && pq.empty())
			cout << 0 << "\n";
		else if (temp == 0)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
		else
			pq.push(temp);
	}
return 0;
}
