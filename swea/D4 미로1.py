from collections import deque

dx = [0,1,0,-1]
dy = [1,0,-1,0]
for test_case in range(1,11):
    mapp = []
    T = int(input())
    bool_is = True
    for i in range(16):
        temp = list(input())
        mapp.append(temp)
    q = deque([])
    q.append((1,1))
    while q:
        x,y= q.pop()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if 0<=nx<16 and 0<=ny<16:
                if mapp[nx][ny] == "0":
                    mapp[nx][ny]= "1"
                    q.appendleft((nx,ny))
                if mapp[nx][ny] == "3":
                    print('#{} {}'.format(test_case, 1))
                    bool_is=False
                    break
    if bool_is:
        print('#{} {}'.format(test_case, 0))

    