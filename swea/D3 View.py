

T = 10
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    building = list(map(int,input().split()))
    s = 0
    for i in range(2,len(building)-2):
        cur_h = building[i]
        left1 = building[i-1]
        left2 = building[i-2]
        right1 = building[i+1]
        right2 = building[i+2]
        rst = max(left1,left2,right1,right2)
        if rst < cur_h:
            s += cur_h - rst
    print("#{} {}".format(test_case,s))



