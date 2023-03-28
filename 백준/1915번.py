n,m = map(int,input().split())

mm = []
for _ in range(n):
    mm.append(list(map(int,list(input()))))



dp = [[0]*m for _ in range(n)]
maxi = 0
for i in range(n):
    for j in range(m):
        if mm[i][j] == 1:
            dp[i][j] = 1
        if i>0 and j>0 and mm[i][j] == 1:

            dp[i][j] += min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])
        maxi = max(maxi,dp[i][j])
print(maxi*maxi)