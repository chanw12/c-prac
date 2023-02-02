#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	int N, M, B;
	scanf("%d %d %d", &N, &M, &B);
	vector<vector<int>> v (N, vector<int>(M));
	int sum=0;
	int mini=1000, maxi=-1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &v[i][j]);
			sum += v[i][j];
			maxi = max(maxi, v[i][j]);
			mini = min(mini, v[i][j]);
		}
	}
	int temp = B;
	int time = 100000000;
	int h;
	for (int k = mini; k <= 256; k++)
	{
		B = temp;
		int pau = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				B += v[i][j] - k;
				if (v[i][j] - k > 0)
				{
					pau += (v[i][j]-k) * 2;
				}
				else
				{
					pau += k - v[i][j];
				}

				
			}
		}
		if (B < 0)
			continue;
		if (time >= pau)
		{
			time = pau;
			h = k;
		}
	}
	printf("%d %d", time, h);
	return 0;
}