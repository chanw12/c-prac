
T = 10

for test_case in range(1, T + 1):
    n = int(input())
    maxi = 0
    graph = [0 for _ in range(100)]
    temp = []
    for i in range(100):
        temp = list(map(int,input().split()))
        for j in range(100):
            graph[j] += temp[j]
        maxi = max(maxi,sum(temp))
    maxi = max(maxi,max(graph))
    print("#{} {}".format(n,maxi))

# swea 문제는 보통 메모리의 제약이 심해 temp = []같이 리스트를 미리 생성해두어야 한다


