
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    prob = list(map(int,input().split()))
    # temp = set([])
    # for i in range(1<<len(prob)):
    #     summ = 0
    #     for j in range(len(prob)):
    #         if i & (1<<j):
    #             summ += prob[j]
    #     temp.add(summ)
    # print(temp)
    # print("#{} {}".format(test_case,len(temp)))

    summ = sum(prob)
    dp = [[0 for _ in range(summ+1)] for _ in range(len(prob)+1)]
    for i in range(len(prob)+1):
        dp[i][0] = 1
    for i in range(1,len(prob)+1):
        for j in range(summ+1):
            if dp[i-1][j] == 1:
                dp[i][j] = 1
                if j+prob[i-1] <=summ:
                    dp[i][j+prob[i-1]] = 1
    cnt = 0
    for i in range(summ+1):
        if dp[-1][i] == 1:
            cnt+=1
    print("#{} {}".format(test_case,cnt))

