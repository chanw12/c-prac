import sys
sys.stdin = open("input.txt", "r")
for test_case in range(10):
    n = int(input())
    new_map = []
    mapp = []
    for _ in range(100):
        mapp.append(list(input().split()))

    for i in range(100):
        temp = ''
        for j in range(100):
            if mapp[j][i] != '0':
                temp += (mapp[j][i])
        new_map.append(temp)
    rst = 0
    for i in range(100):
        rst += new_map[i].count('12')
    print(f'#{test_case+1} {rst}')

        
    

        

