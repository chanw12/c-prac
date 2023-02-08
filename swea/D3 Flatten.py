
T = 10

for test_case in range(1, T + 1):
    n = int(input())
    q = []
    num = list(map(int,input().split()))

    for i in range(n-1):
        num = sorted(num)
        if num[-1] - num[0] <=1:
            break
        num[0] += 1
        num[-1] -=1
    num=sorted(num)
    print("#{} {}".format(test_case,num[-1]-num[0]))



