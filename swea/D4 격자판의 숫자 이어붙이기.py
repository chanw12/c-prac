
T = int(input())

dx=[0,1,0,-1]
dy = [1,0,-1,0]

def dfs(start,ss):
    global li
    if len(ss) ==7:
        li.add(ss)
        return
    for i in range(4):
        nx = start[0] + dx[i]
        ny = start[1] + dy[i]
        if 0<=nx<4 and 0<=ny<4:
            dfs((nx,ny),ss+mapp[nx][ny])
            







for test_case in range(1, T + 1):
    mapp = []
    visited = [[False for _ in range(4)] for _ in range(4)]
    li = set([])
    for i in range(4):
        temp = list(input().split())
        mapp.append(temp)
    for i in range(4):
        for j in range(4):
            dfs((i,j),"")
    print("#{} {}".format(test_case,len(li)))
