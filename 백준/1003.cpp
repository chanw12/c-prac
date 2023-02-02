#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;


struct k {
	int cnt0=0;
	int cnt1=0;
};
int main() {
	k Dp[100000];
	int T;
	scanf("%d", &T);


for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		Dp[0].cnt0 = 1;
		Dp[0].cnt1 = 0;
		Dp[1].cnt0 = 0;
		Dp[1].cnt1 = 1;
		for (int i = 2; i <=n; i++)
		{
			Dp[i].cnt0 = Dp[i - 1].cnt0 + Dp[i - 2].cnt0;
			Dp[i].cnt1 = Dp[i - 1].cnt1 + Dp[i - 2].cnt1;
		}
		printf("%d %d\n", Dp[n].cnt0, Dp[n].cnt1);
		

	}
	return 0;
}