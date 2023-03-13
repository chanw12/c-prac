from collections import deque
maxx = []
dx = [0,1,0,-1]
dy = [1,0,-1,0]
#r , d, l,u

def solution(board):
    answer = 0
    
    n = len(board)
    visited = [[1e9 for _ in range(n)] for _ in range(n)]
    visited[0][0] = 0
    dfs(0,0,5,n,visited,board)
    
    return min(maxx)

def dfs(x,y,direc,n,visited,board):

    if x == n-1 and y == n-1:
        maxx.append(visited[n-1][n-1])
            
        return
    for i in range(4):
        nx = x+dx[i]
        ny = y + dy[i]
        if nx >=0 and nx<n and ny>=0 and ny< n and not board[nx][ny]:
            if (direc == i or direc == 5) and visited[nx][ny] >= visited[x][y] + 100:
                visited[nx][ny] = visited[x][y] + 100
                dfs(nx,ny,i,n,visited,board)
            else:
                if visited[nx][ny] >= visited[x][y] +600:
                    visited[nx][ny] =visited[x][y] + 600
                    dfs(nx,ny,i,n,visited,board)
        
