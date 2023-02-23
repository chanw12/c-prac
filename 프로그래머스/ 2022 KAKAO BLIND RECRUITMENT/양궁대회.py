def solution(n, info):
    answer = []
    maxx=0
    for i in range(1<<10):
        temp = [0 for _ in range(11)]
        cnt = 0
        a=0
        l = 0
        for k in range(10):
            if i & (1<<k):
                l += 10-k
                cnt += info[k]+1
                temp[k] = info[k] +1
            else:
                if info[k]:
                    a += 10-k
        if cnt <= n:
            temp[10] = n-cnt
            if maxx <= l-a:
                maxx = l-a
                answer = temp
        else:
            continue
    if maxx == 0:
        return [-1]

    return answer