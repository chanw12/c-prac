from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
answer = []
mapp = [[] for _ in range(n+1)]
temp = [0 for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    mapp[a].append(b)
    temp[b] +=1


q = deque([])

for i in range(1,n+1):
    if temp[i] == 0:
        q.append(i)
while q:
    cur = q.popleft()
    for t in mapp[cur]:
        temp[t] -=1
        if temp[t] == 0:
            q.append(t)
    answer.append(cur)
for i in answer:
    print(i,end=' ')
print()

    
