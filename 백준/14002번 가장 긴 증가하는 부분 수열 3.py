n = int(input())
l = list(map(int,input().split()))
temp = []

for ll in l:
    if len(temp)==0:
        temp.append(ll)
    elif temp[-1] < ll:
        temp.append(ll)
    else:
        left = 0
        right = len(temp)-1
        while left < right:
            mid = (left + right)//2
            if temp[mid] < ll:
                left = mid +1
            else:
                right = mid
        temp[right] = ll
print(len(temp))
