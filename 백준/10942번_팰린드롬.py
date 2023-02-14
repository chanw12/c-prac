import sys
input = sys.stdin.readline

n = int(input())
num = list(map(int,input().split()))
m = int(input())

dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    dp[i][i] = 1
    if i != n-1:
        if num[i]== num[i+1]:
            dp[i][i+1] = 1
        else:
            dp[i][i+1] = 0


for j in range(2,n):
    for i in range(n):
        if i+j < n:
            if num[i] == num[i+j]:
                if dp[i+1][i+j-1] == 1:
                    dp[i][i+j] = 1
                else:
                    dp[i][i+j] = 0


for i in range(m):
    s,e = map(int,input().split())
    print(dp[s-1][e-1])
