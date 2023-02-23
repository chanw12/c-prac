from collections import deque
def solution(queue1, queue2):
    answer = -2
    sum1,sum2 = sum(queue1),sum(queue2)
    n = len(queue1)
    index = n-1
    q = deque(queue1+queue2)
    cnt = 0
    if sum1 + sum2 %2 == 1:
        return -1
    while cnt < n*6:
        if sum1 > sum2:
            temp = q.popleft()
            q.append(temp)
            index -=1
            sum1 -= temp
            sum2 += temp
            cnt +=1
        elif sum1 < sum2:
            index +=1
            temp = q[index]
            sum1 += temp
            sum2 -= temp
            cnt +=1
        else:
            break
    
    if cnt>=n*6:
        answer = -1
    else:
        answer = cnt
            
            
        
    return answer