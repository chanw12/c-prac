n = int(input())
chu = list(map(int,input().split()))
m = int(input())
gu = list(map(int,input().split()))

gg = max(gu)


dp = [[0]*(gg+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,gg+1):
        if j == chu[i-1] and dp[i][j] == 0:
            dp[i][j] = chu[i-1]
print(dp)

