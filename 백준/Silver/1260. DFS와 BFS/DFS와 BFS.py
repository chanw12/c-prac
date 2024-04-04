from re import X
import sys
from collections import deque
input = sys.stdin.readline

deq = deque()
N,M,V = map(int,input().split())
l = [[] for _ in range(N+1)]
visited_b = [0] * (N+1)
visited_d = [0] * (N+1)

for _ in range(M):
    a,b = map(int,input().split())
    l[a].append(b)
    l[b].append(a)
for i in range(len(l)):
    l[i].sort()



def dfs(start):
    visited_d[start]= 1
    print(start,end=' ')
    visited_d[start]=1
    for i in l[start]:
        if visited_d[i]==0:
            dfs(i)
            visited_d[i]=1
                

def bfs(start):
    visited_b[start]= 1
    deq.append(start)
    while deq:
        num = deq.popleft()
        print(num,end=" ")
        for i in range(len(l[num])):
            if visited_b[l[num][i]] == 0 :
                visited_b[l[num][i]] =1
                deq.append(l[num][i])

dfs(V)
print()
bfs(V)



