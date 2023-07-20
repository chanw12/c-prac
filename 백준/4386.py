from collections import deque
import math


n = int(input())
star = []
for _ in range(n):
    x,y = map(float,input().split())
    star.append([x,y])
distance = []
parent = [i for i in range(n)]
for i in range(n):
    for j in range(i+1,n):
        a = abs(star[i][0] - star[j][0])
        b = abs(star[i][1] - star[j][1])
        dis = math.sqrt(a**2 + b**2)
        distance.append((dis,i,j))
distance = sorted(distance)
distance = deque(distance)

def find(x):
    if x == parent[x]:
        return x
    else:
        return find(parent[x])
    
def union(a,b):
    a = find(a)
    b = find(b)
    parent[b] = a


cnt = 0
rst = 0
while cnt < n-1:
    dis,a,b = distance.popleft()
    if find(a) == find(b):
        continue
    union(a,b)
    cnt +=1
    rst+= dis

print(rst)



