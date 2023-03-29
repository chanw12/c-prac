n,k = map(int,input().split())

array = [(0,0)]

for _ in range(n):
    w,v = map(int,input().split())
    array.append((w,v))

dp = [[0]*(k+1) for _ in range(n+1)]
array = sorted(array,key=lambda x:x[1])
for i in range(1,n+1):
    
    for j in range(1,k+1):
        weight, value = array[i]
        if j >= weight:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight]+value)
        else:
            dp[i][j] = dp[i-1][j]
print(dp)
print(dp[n][k])