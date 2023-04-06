
from itertools import combinations
from itertools import permutations

n = int(input())
num = []
for _ in range(n):
    num.append(list(map(int,input().split())))


ll = [i for i in range(n)]
lll = list(combinations(ll,n//2))

def call(l):
    rst = list(permutations(l,2))
    cnt = 0
    for i in rst:
        cnt += num[i[0]][i[1]]
    return cnt
ll_set = set(ll)
mini = 1000000
for i in range(len(lll)):
    compare_set = set(lll[i])
    rst = list(ll_set.difference(compare_set))
    mini = min(abs(call(rst)-call(lll[i])),mini)
print(mini)
