import heapq
INF = int(1e9)
n,m,r = map(int,input().split())
itemN = list(map(int,input().split()))
v = [[] for _ in range(n+1)]

for i in range(r):
    a,b,l = map(int,input().split())
    v[a].append((b,l))
    v[b].append((a,l))



def dijk(start):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0
    while q:
        dist,now = heapq.heappop(q)

        if distance[now] < dist:
            continue
        
        for i in v[now]:
            if distance[i[0]] > distance[now] + i[1]:
                distance[i[0]] = distance[now] + i[1]
                heapq.heappush(q,(distance[now]+i[1],i[0]))
maxi = 0
for i in range(1,n+1):
    distance = [INF] * (n+1)
    dijk(i)
    sum = 0
    for j in range(1,n+1):
        if distance[j] <= m:
            sum+= itemN[j-1]
    maxi = max(maxi,sum)
print(maxi)



    

