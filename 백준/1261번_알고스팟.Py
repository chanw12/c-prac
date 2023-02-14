import heapq
dx= [0,1,0,-1]
dy = [1,0,-1,0]

m,n = map(int,input().split())
graph = []
for _ in range(n):
    temp = list(map(int,input()))
    graph.append(temp)


distance = [[1e9 for _ in range(m)] for _ in range(n)]



def dijk():
    q = []
    heapq.heappush(q,(0,(0,0)))

    while q:
        dis,cur = heapq.heappop(q)

        if distance[cur[0]][cur[1]] <= dis:
            continue
        distance[cur[0]][cur[1]] = dis
        for i in range(4):
            nx,ny = cur[0]+dx[i],cur[1]+dy[i]
            if nx>=0 and nx<n and ny>=0 and ny<m:
                if graph[nx][ny] == 0:
                    nd = dis
                    heapq.heappush(q,(nd,(nx,ny)))
                
                else:
                    nd = dis +1
                    heapq.heappush(q,(nd,(nx,ny)))
                
                

dijk()
print(distance[n-1][m-1])