
def sol(x):
    global cnt
    if x == n:
        cnt +=1
        return
    else:
        for i in range(n):
            mapp[x] = i
            if hel()

T = int(input())

for test_case in range(T):
    n = int(input())
    cnt = 0
    mapp = [0] * n
