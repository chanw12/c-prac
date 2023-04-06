


T = int(input())

def dfs(start,cnt,s,end):
    global min_list
    if cnt == len(pp):
        s += abs(start[0]-end[0]) + abs(start[1]-end[1])
        min_list.append(s)
        return

    for i in range(len(pp)):
        if visited[i] == False:

            visited[i] = True
            s += abs(start[0]-pp[i][0]) + abs(start[1]-pp[i][1])
            dfs((pp[i][0],pp[i][1]),cnt+1,s,end)
            s -= abs(start[0]-pp[i][0]) + abs(start[1]-pp[i][1])
            visited[i] = False
        


for test_case in range(1,T+1):
    n = int(input())
    temp = list(map(int,input().split()))

    start = (temp[0],temp[1])
    end = (temp[2],temp[3])
    
    pp = []
    
    for i in range(4,len(temp),2):
        pp.append((temp[i],temp[i+1]))
    visited = [False for _ in range(len(pp))]
    min_list = []
    dfs(start,0,0,end)

    print('#{} {}'.format(test_case, min(min_list)))


