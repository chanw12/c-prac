from collections import deque


n,m = map(int,input().split())
ll = [[] for _ in range(n+1)]
for _ in range(m):
    temp = list(map(int,input().split()))
    for i in range(2,temp[0]+1):
        if temp[i-1] not in ll[temp[i]]:
            ll[temp[i]].append(temp[i-1])
rst = []
q = deque()
for i in range(1,n+1):
    if len(ll[i]) == 0:
        q.append(i)

while q:
    current = q.popleft()
    for i in range(1,n+1):
        if current in ll[i]:
            ll[i].remove(current)
            if len(ll[i]) == 0:
                q.append(i)
    rst.append(current)

for i in range(1,n+1):
    if len(ll[i]) != 0:
        print(0)
        exit()

for i in rst:
    print(i)

    
