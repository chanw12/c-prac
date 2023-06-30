import sys
input = sys.stdin.readline
n = int(input())
ll = list(map(int,input().split()))

min_sum = 10000000

rst = 0
a = 0
b = n-1
a_rst = 0
b_rst = 0
check = False
if ll[-1] < 0:
    check = True
    print(ll[n-2],ll[n-1])
if ll[0] > 0:
    check = True
    print(ll[0],ll[1])


while a<b and check == False:
    temp = ll[a] + ll[b]
    if abs(temp) < min_sum:
        min_sum = abs(temp)
        a_rst = a
        b_rst = b
        if min_sum == 0:
            break
    if temp > 0:
        b -= 1
    elif temp < 0:
        a +=1
if check == False:
    print(ll[a_rst],ll[b_rst])
    


