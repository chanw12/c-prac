import sys

pre = []
while True:
    try:
        num = int(input())
        pre.append(num)
    except:
        break

sys.setrecursionlimit(10000)
def sol(arr):
    if len(arr)==1:
        print(arr[0])
    else:
        left = []
        right = []
        mid = arr[0]
        for i in range(1,len(arr)):
            if arr[i] > mid:
                right.append(arr[i])
            else:
                left.append(arr[i])
        if len(left)>0:
            sol(left)
        if len(right)>0:
            sol(right)
        print(mid)
sol(pre)
        