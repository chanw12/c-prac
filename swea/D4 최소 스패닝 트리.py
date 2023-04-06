import heapq
import sys
sys.setrecursionlimit(10000)
v,e = map(int,input().split())
parent = [i for i in range(v+1)]


def get_parent(x):
    if parent[x] == x:
        return x
    parent[x] = get_parent(parent[x]) # get_parent 거슬러 올라가면서 parent[x] 값도 갱신
    return parent[x]

def union_parent(a, b):
    a = get_parent(a)
    b = get_parent(b)

    if a < b: # 작은 쪽이 부모가 된다. (한 집합 관계라서 부모가 따로 있는 건 아님)
        parent[b] = a
    else:
        parent[a] = b        

def same_parent(a, b):
    return get_parent(a) == get_parent(b)


sum = 0
q = []
for i in range(e):
    a,b,c= map(int,input().split())
    heapq.heappush(q,(c,a,b))

while q:
    cur = heapq.heappop(q)
    if not same_parent(cur[1],cur[2]):
        union_parent(cur[1],cur[2])
        sum += cur[0]
    else:
        continue
    


print(sum)