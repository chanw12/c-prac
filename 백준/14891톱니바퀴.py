
from collections import deque



gear = [[]]
for i in range(4):
    temp = deque(list(input()))
    gear.append(temp) 



k = int(input())
for i in range(k):
    left = []
    right = []
    n,d = map(int,input().split())
    if d == -1:
        a=1
        b=1
        for j in range(n-1,0,-1):
            if gear[j+1][6] != gear[j][2]:
                left.append(j)
            else:
                break
        for j in range(n+1,5):
            if gear[j-1][2] != gear[j][6]:
                right.append(j)
            else:
                break
        for j in left:
            gear[j].rotate(a)
            a*=-1
        for j in right:
            gear[j].rotate(b)
            b *= -1
    if d == 1:
        a=-1
        b=-1
        for j in range(n-1,0,-1):
            if gear[j+1][6] != gear[j][2]:
                left.append(j)
            else:
                break
        for j in range(n+1,5):
            if gear[j-1][2] != gear[j][6]:
                right.append(j)
            else:
                break
        for j in left:
            gear[j].rotate(a)
            a*=-1
        for j in right:
            gear[j].rotate(b)
            b*=-1

    gear[n].rotate(d)
    

rst = 0
for i in range(1,5):
    if gear[i][0] == '1':
        rst+= 2**(i-1)
print(rst)


                

                

    



