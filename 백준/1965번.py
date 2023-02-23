n = int(input())
arr = list(map(int,input().split()))
dp = [0 for _ in range(len(arr))]


for i in range(len(arr)):
    for j in range(i+1,len(arr)):
        if arr[i] < arr[j]:
            dp[j] = max(dp[i]+1,dp[j])
        
print(max(dp)+1)



temp = [-1e9]
for ll in arr:
    if temp[-1] < ll:
        temp.append(ll)
    else:
        left = 0
        right = len(temp)-1
        while left<right:
            mid = (left+right)//2
            if temp[mid] < ll:
                left = mid +1
            else:
                right = mid
        temp[right] = ll
print(len(temp)-1)
            