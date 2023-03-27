import heapq
INF = int(1e9)
dis = [INF] * (201)
graph = [[] for _ in range(201)]

def dijk(start):
    q = []
    dis[start] = 0
    heapq.heappush(q,(0,start))
    
    while q:
        dist,now = heapq.heappop(q)
        if dis[now] < dist:
            continue
        for i in graph[now]:
            if dist+i[1] < dis[i[0]]:
                dis[i[0]] = dist+i[1]
                heapq.heappush(q,(dist+i[1],i[0]))
    
    

def solution(n, s, a, b, fares):
    answer = 0

    for fare in fares:
        graph[fare[0]].append((fare[1],fare[2]))
        graph[fare[1]].append((fare[0],fare[2]))
    mini = INF
    dijk(s)
    temp = [0]*201
    for i in range(1,n+1):
        temp[i] = dis[i]
        dis[i] = INF
    for i in range(1,n+1):
        dijk(i)
        tempa = dis[a]
        tempb = dis[b]
        tempsum = temp[i] + tempa+tempb
        if tempsum < mini:
            mini = tempsum

        for j in range(1,n+1):
            dis[j] = INF
    answer = mini        
    
    return answer