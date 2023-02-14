n = int(input())
ll = list(map(int,input().split()))
temp = [0]

for l in ll:
    if temp[-1] < l:
        temp.append(l)
    else:
        left = 0
        right = len(temp)-1
        while left< right:
            mid = (left+right)//2
            if temp[mid] < l:
                left = mid+1
            else:
                right = mid
        temp[right] = l


print(len(temp)-1)


