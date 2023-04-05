t = int(input())

for _ in range(t):
    k = int(input())
    data = list(map(int,input().split()))
    dp = [[0]*(k+1) for _ in range(k+1)]

    for i in range(0,k-1):
        dp[i][i+1] = data[i] + data[i+1]
    for i in range(2,k):
        for j in range(k-i):
            dp[j][j+i] = min([dp[j][p]+dp[p+1][j+i] for p in range(j,j+i)]) + sum(data[j:j+i+1])

    print(dp[0][k-1])
