
T = int(input())
graph = []
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    graph = []
    temp = []
    summ = 0
    s = n//2
    e = n//2
    for i in range(n):
        temp = input()
        temp = list(str(temp))
        graph.append(temp)
    for i in range(n):
        for j in range(s,e+1):
            summ += int(graph[i][j])
        if i < n//2:
            s-=1
            e+=1
        else:
            s+=1
            e-=1
    print("#{} {}".format(test_case,summ))
    
    
    