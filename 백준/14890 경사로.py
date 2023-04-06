n,l = map(int,input().split())
mapp= []
for _ in range(n):
    temp = list(map(int,input().split()))
    mapp.append(temp)

for i in range(n):
    tp =[]
    for j in range(n):
        tp.append(mapp[j][i])
    mapp.append(tp)




def sol(line):
    used = [False] * n
    for i in range(1,len(line)):
        if line[i] != line[i-1] and used[i] == False:
            if abs(line[i]-line[i-1]) >=2:
                return False
            if line[i] > line[i-1]:#왼쪽에 놔야하니까 왼쪽 탐색
                cnt = 0
                for j in range(i-1,-1,-1):
                    if line[i-1] ==line[j] and used[j] == False:
                        cnt+=1
                        used[j] = True
                    else:
                        break
                        
                    if cnt >= l:
                        break
                if cnt < l:
                    return False
                
            if line[i] < line[i-1]:
                cnt = 0
                for j in range(i,n):
                    if line[i] == line[j] and used[j] == False:
                        cnt+=1
                        used[j]=True
                    else:
                        break
                    if cnt>=l:
                        break
                if cnt < l:
                    return False
    return True
rst = 0
for i in mapp:
    if sol(i):
        rst +=1
print(rst)


