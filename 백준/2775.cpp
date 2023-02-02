#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {
	
	int T;
	cin >> T;
	for (int p = 0; p < T; p++)
	{

		int k, n;
		cin >> k >> n;
		vector< vector<int>> Dp(k+1, vector <int>(n+1));
		for (int i = 0; i <= n; i++)
		{
			Dp[0][i] = i;
		}

		for (int i = 1; i <=k; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j == 0)
					Dp[i][j] = Dp[i - 1][j];
				else
				{
					Dp[i][j] = Dp[i][j - 1] + Dp[i - 1][j];
				}
			}
		}
		cout << Dp[k][n] << endl;
		
	}
	
	return 0;
}
