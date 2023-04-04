m,n = map(int,input().split())
array = []
for _ in range(m):
    temp = list(map(int,input().split()))
    array.append(temp)
da = [0,1,0,-1]
db = [1,0,-1,0]
dp = [[-1]*n for _ in range(m)]

def dfs(a,b):


    if a == m-1 and b == n-1:
        return 1

    if dp[a][b] != -1:
        return dp[a][b]

    dp[a][b] = 0

    for i in range(4):
        na = a + da[i]
        nb = b + db[i]
        if 0<=na <m and 0<=nb<n and array[na][nb] < array[a][b]:
            dp[a][b] += dfs(na,nb)


    return dp[a][b]

dfs(0,0)



print(dp[0][0])