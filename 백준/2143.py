
from collections import defaultdict


T = int(input())
na = int(input())
a = list(map(int,input().split()))
nb = int(input())
b = list(map(int,input().split()))
summ = defaultdict(int)
cnt = 0

for i in range(na):
    for j in range(i,na):
        summ[sum(a[i:j+1])] += 1

for i in range(nb):
    for j in range(i,nb):
        cnt+= summ[T - sum(b[i:j+1])]
print(cnt)
