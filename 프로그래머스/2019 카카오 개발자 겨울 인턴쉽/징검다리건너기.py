
def solution(stones, k):
    answer = 0
    
    start = 0
    end = max(stones)
    while start<=end:
        mid = (start + end)//2
        count = 0
        for i in stones:
            if count < k:
                if i-mid <= 0:
                    count += 1
                else:
                    count = 0
            else:
                break
        if count < k:
            start = mid +1
        else:
            end = mid -1
            answer = mid
    return answer