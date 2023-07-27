N = int(input())

MOD = 1000000000
MAX = (1<<10) -1

def solution():
    dp = [[0]*(MAX+1) for _ in range(10)]
    for i in range(1,10):
        dp[i][1<<i] = 1
    

    for _ in range(1,N):
        new_dp = [[0]*(MAX+1) for _ in range(10)]
        for i in range(10):
            for j in range(MAX+1):
                if i>0:
                    new_dp[i][j|1<<i] = (new_dp[i][j|1<<i] + dp[i-1][j])%MOD
                if i<9:
                    new_dp[i][j|1<<i] = (new_dp[i][j|1<<i] + dp[i+1][j])%MOD
                
        dp = new_dp
    return sum(dp[i][MAX] for i in range(10))%MOD

print(solution())