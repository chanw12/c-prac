doku = [list(map(int,input())) for _ in range(9)]

# 행 , 열 , 박스체크

check1 = [[False]*9 for _ in range(9)] # 행에 있는 수 
check2=  [[False]*9 for _ in range(9)]
check3 = [[False]*9 for _ in range(9)]

for i in range(9):
    for j in range(9):
        if doku[i][j]:
            check1[i][doku[i][j]-1] = True
            check2[j][doku[i][j]-1] = True
            check3[i//3*3 + j//3][doku[i][j]-1] = True

def dfs(a,b):
    if a == 9:
        for x in doku:
            x = map(str,x)
            x="".join(x)
            print(x)
        exit(0)
    if doku[a][b]:
        dfs(a+(b+1)//9,(b+1)%9)
        return
    for k in range(9):
        if check1[a][k] or check2[b][k] or check3[a//3*3 + b//3][k]:
            continue
        check1[a][k] = check2[b][k] = check3[a//3*3 + b//3][k]= True
        doku[a][b] = k+1
        dfs(a+(b+1)//9,(b+1)%9)
        check1[a][k] = check2[b][k] = check3[a//3*3 + b//3][k]= False
        doku[a][b] = 0


dfs(0,0)



                    


    
