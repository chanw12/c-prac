from itertools import combinations


n = int(input())
dice = list(map(int,input().split()))
max_dice = max(dice)
sum_dice = sum(dice)
dice = [100001] + dice

three = [[1,2,3],[1,2,4],[1,4,5],[1,3,5],[6,2,3],[6,2,4],[6,4,5],[6,3,5]]

two = []
for i in range(1,7):
    for j in range(i+1,7):
        if i+j == 7 or i == j:
            continue
        two.append((i,j))
three_min = 10000000
two_min = 10000000
for i in three:
    temp = dice[i[0]] + dice[i[1]] + dice[i[2]]
    if three_min > temp:
        three_min = temp

for i in two:
    temp = dice[i[0]] + dice[i[1]]
    if two_min > temp:
        two_min = temp
rst = 0
if n == 1:
    rst = sum_dice-max_dice

elif n == 2:
    rst = three_min *4 + two_min * 4

else:
    fir = (n-2)*(n-2) + ((n-2)*(n-1))*4
    sec = (n-2)*4 + (n-1)*4
    thr = 4

    rst = fir * min(dice) + sec*two_min + thr*three_min

print(rst)