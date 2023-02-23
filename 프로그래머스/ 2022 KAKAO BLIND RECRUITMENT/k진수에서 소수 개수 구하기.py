import math
def solution(n, k):
    answer = -1

    def jinsu(n, m):
        hihi = []
        while True:
            if n // m == 0:
                hihi.append(n)
                break
            hihi.append(n%m)
            n = n // m
        hihi.reverse()
        return int("".join(map(str,hihi)))
    
    n = str(jinsu(n,k))
    print(n)
    def is_prime(n):
        if n == 1:
            return False
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    temp = ''
    cnt=0
    for i in range(len(n)):
        if n[i]=='0' or i==len(n)-1:
            if i==len(n)-1 and n[i] != '0':
                temp += n[i]
            if len(temp) >0 and is_prime(int(temp)):
                cnt+=1

            temp= ''

        else:
            if n[i] != 1:
                temp += n[i]
    
    
    
    return cnt