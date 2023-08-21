n = int(input())

ll = list(map(int,input().split()))

dp = [[ll[i]] for i in range(n)]
for i in range(1,n):
    temp = []
    kk = [ll[i]]
    for j in range(0,i):
        if ll[i] > ll[j]:
            if len(dp[j])+1> len(temp):
                temp = dp[j] + kk

    if len(dp[i]) < len(temp):
        dp[i] = temp


dp = sorted(dp,key= lambda x:len(x))
print(len(dp[-1]))
for i in dp[-1]:
    print(i,end=" ")
print()
