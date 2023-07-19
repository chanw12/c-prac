from bisect import bisect_left, bisect_right
import sys
from itertools import combinations


input = sys.stdin.readline
n = int(input())

ll = sorted(list(map(int,input().split())))

ans = 4000000001
rst = []
for i in range(n-2):
    left = i+1
    right = n-1

    while left < right:
        msum = ll[left] + ll[right] + ll[i]
        if abs(msum) < ans:
            ans = abs(msum)
            rst = sorted([ll[left],ll[right],ll[i]])
        if msum < 0:
            left +=1
        elif msum>0:
            right -=1
        else:
            print(*rst)
            exit(0)
print(*rst)
