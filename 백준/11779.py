import heapq
n = int(input())
m = int(input())
INF = int(1e9)
distance = [INF] * (n+1)
graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b,w = map(int,input().split())
    graph[a].append((b,w))

start,end = map(int,input().split())

def dijk(s):
    q = []
    heapq.heappush(q,(0,[s]))
    distance[s] = 0

    while q:
        dist,now = heapq.heappop(q)
        if distance[now[-1]] < dist:
            continue
        if now[-1] == end:
            result = now
            return result

        for i in graph[now[-1]]:
            if distance[i[0]] > distance[now[-1]] + i[1]:
                distance[i[0]] = distance[now[-1]] + i[1]
                temp = [i[0]]
                heapq.heappush(q,(distance[now[-1]]+i[1],now+temp))

result = dijk(start)


print(distance[end])
print(len(result))
for i in result:
    print(i,end=" ")
print()

