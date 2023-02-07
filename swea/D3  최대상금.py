
from itertools import combinations
T = int(input())
for test_case in range(1, T + 1):

    num,n = input().split()
    n = int(n)
    arr = [set([]) for i in range(n+1)]
    arr[0].add(int(num))
    temp = [i for i in range(len(str(num)))]

    for j in range(1,n+1):
        for k in arr[j-1]:
            tp = list(str(k))
            for p in range(0,len(tp)-1):
                for q in range(p+1,len(tp)):
                    tp2 = tp[:]
                    tp2[p],tp2[q] = tp2[q],tp2[p]
                    arr[j].add(int(''.join(tp2)))
    
    print("#{} {}".format(test_case,max(arr[n])))

                    
            
                
                
                

