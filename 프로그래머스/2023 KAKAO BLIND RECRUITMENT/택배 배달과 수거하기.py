def solution(cap, n, deliveries, pickups):
    answer = 0
    go = n -1
    back = n -1
    while go>=0 and deliveries[go] == 0:
        go -= 1
    while back >= 0 and pickups[back] == 0:
        back -=1
        
    while go >=0 or back >= 0:
        answer += (max(go,back)+1) * 2
        temp = cap
        while temp and go >=0:
            if deliveries[go] > temp:
                deliveries[go] -= temp
                temp = 0
            else:
                temp -= deliveries[go]
                deliveries[go] = 0
                while go >= 0 and deliveries[go] == 0:
                    go -= 1
        temp = cap
        while temp and back >=0:
            if pickups[back] > temp:
                pickups[back] -= temp
                temp = 0
            else:
                temp -= pickups[back]
                pickups[back] = 0
                while back >= 0 and pickups[back] == 0:
                    back -= 1
    return answer