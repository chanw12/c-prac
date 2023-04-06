import sys
sys.stdin = open("input.txt", "r")

for test_case in range(10):
    n = int(input())
    ladder = []
    for i in range(100):
        ladder.append(list(map(int,input().split())))
    idx = 0
    for i in range(100):
        if ladder[99][i] == 2:
            idx = i
    
    y = 99
    x = idx
    
    while y != 0:
        ladder[y][x] = 0
        if x-1>=0 and ladder[y][x-1] == 1:
            x = x-1
        elif x+1<=99 and ladder[y][x+1] == 1:
            x = x+1
        else:
            y = y-1

    print(f'#{n} {x}')
