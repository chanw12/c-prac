ll = list(map(int,input().split()))

ll.pop()
n = len(ll)


def moving(a,b):
    if b == 0:
        if a == 0:
            return 0
        else:
            return 2
    elif b == a:
        return 1
    elif abs(b-a) == 1 or abs(b-a) == 3:
        return 3
    else:
        return 4
    




dp = [[[400000 + 1 for _ in range(5)] for _ in range(5)] for _ in range(n + 1)]
dp[-1][0][0] = 0
for i in range(n):
    #왼발을 움직이는 경우
    for r in range(5):
        for k in range(5):
            dp[i][ll[i]][r] = min(dp[i][ll[i]][r],dp[i-1][k][r] + moving(ll[i],k)) 
    #오른발을 움직이는 경우
    for l in range(5):   
        for k in range(5):
            dp[i][l][ll[i]] = min(dp[i][l][ll[i]],dp[i-1][l][k]+moving(ll[i],k))
m = 1000000

for i in range(5):
    for j in range(5):
        m = min(m,dp[n-1][i][j])
print(m)