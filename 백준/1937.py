def dfs(a,b):
    if dp[a][b]: return dp[a][b]

    dp[a][b] = 1
    for i in range(4):
        na = a + da[i]
        nb = b + db[i]
        if 0<=na<n and 0<=nb <n and mm[a][b] < mm[na][nb]:
            dp[a][b] = max(dp[a][b],dfs(na,nb)+1)

    return dp[a][b]

n = int(input())
mm = []
for _ in range(n):
    mm.append(list(map(int,input().split())))

dp = [[0]*n for _ in range(n)]


da= [1,0,-1,0]
db = [0,-1,0,1]

cnt = 0
for i in range(n):
    for j in range(n):
        cnt = max(cnt,dfs(i,j))
print(cnt)






