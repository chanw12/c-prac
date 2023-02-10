import sys
limit_number = 15000
sys.setrecursionlimit(limit_number)

def solution(numbers):
    answer = []
    for n in numbers:
        kk = 1                  
        n_b = format(n,'b')
        while len(n_b) > 2**kk-1:
            kk+=1
        n_b = format(n,'b').zfill(2**(kk) -1)
        # print(kk)
        # print(n_b)
        if check(0,len(n_b)-1,n_b):
            answer.append(1)
        else:
            answer.append(0)
    return answer

def check(left,right,n_b):
    mid = (left+right)//2

    if len(n_b[left:right])<= 3:
        if n_b[mid] == '0':
            if n_b[left] == '1' or n_b[right] == '1':
                return False
            else:
                return True
        else:
            return True
    else:
        if n_b[mid] != '0':
            return check(left,mid-1,n_b) and check(mid+1,right,n_b)
        else:
            if '1' in n_b[left:right+1]:
                return False
            else:
                return True
                

            
