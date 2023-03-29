n,m = map(int,input().split())

memory = list(map(int,input().split()))
cost = list(map(int,input().split()))

temp = [(0,0)]
rst = []
for i in range(n):
    temp.append((cost[i],memory[i]))
temp = sorted(temp)
summ = sum(cost)

dp = [[0]*(summ+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(summ+1):
        co,mem = temp[i]
        if co <= j:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-co]+mem)
        else:
            dp[i][j] = dp[i-1][j]
        print(i,j,dp[i][j])
        if dp[i][j] >= m:
            rst.append(j)
print(min(rst))