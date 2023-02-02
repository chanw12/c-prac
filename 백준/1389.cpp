#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>


using namespace std;

vector<int> v[1000];
int bfs(int start,int target)
{
	int check_bfs[1000] = { 0, };
	queue<int> q;
	q.push(start);
	check_bfs[start] = 1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];
			if (next == target)
				return check_bfs[current];
			if (!check_bfs[next])
			{
				check_bfs[next] = check_bfs[current]+1;
				q.push(next);
			}

		}
	}
}


int main() {
	int N, M;
	scanf("%d %d", &N, &M);


	for (int i = 0; i < M; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}
	vector<int> count(N+1);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if(i != j)
				count[i] += bfs(i, j);
		}
		printf("%d\n", count[i]);
	}
	int min = 100000;
	int minnum;
	for (int i = 1; i <= N; i++)
	{
		if (count[i] < min)
		{
			minnum = i;
			min = count[i];
		}
		
			
	}
	
	printf("%d", minnum);

	return 0;
}

