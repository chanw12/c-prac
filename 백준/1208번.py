import bisect
from itertools import combinations

import sys
input = sys.stdin.readline

n,s = map(int,input().split())
num = list(map(int,input().split()))

left = num[:n//2]
right = num[n//2:]
sumL = []
sumR = []
cnt = 0

for i in range(len(left)+1):
    temp = combinations(left,i)

    for j in temp:
        sumL.append(sum(j))

for i in range(len(right)+1):
    temp = combinations(right,i)

    for j in temp:
        sumR.append(sum(j))
sumL.remove(0)
sumR.remove(0)
sumL = sorted(sumL)
sumR = sorted(sumR)

if bisect.bisect_left(sumL,s) < len(sumL):
    cnt += bisect.bisect_right(sumL,s) - bisect.bisect_left(sumL,s)
if bisect.bisect_left(sumR,s) < len(sumR):
    cnt += bisect.bisect_right(sumR,s) - bisect.bisect_left(sumR,s)
for i in sumL:
    temp = s - i
    cnt += bisect.bisect_right(sumR,temp) - bisect.bisect_left(sumR,temp)
print(cnt)
    