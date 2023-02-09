
T = 10

temp = []
temp1 = []
temp2=[]
for test_case in range(1, T + 1):
    n = int(input())
    temp = []
    temp1 = [[] for _ in range(8)]
    s = 0
    for i in range(8):
        tt = input()
        temp = list(str(tt))
        temp1[i] = temp
    
    for i in range(8):
        temp = temp1[i]
        for j in range(8-n+1):
            if n % 2 == 0:
                if temp[j:j+n//2] == list(reversed(temp[j+n//2:j+n])):
                    s+=1
        
            else:
                if temp[j:j+n//2] == list(reversed(temp[j+n//2+1:j+n])):
                    s +=1
    

    temp1 = list(zip(*temp1))

    for i in range(8):
        temp = temp1[i]
        for j in range(8-n+1):
            if n % 2 == 0:
                if temp[j:j+n//2] == tuple(reversed(temp[j+n//2:j+n])):
                    s+=1
            else:
                if temp[j:j+n//2] == tuple(reversed(temp[j+n//2+1:j+n])):
                    s +=1

    print("#{} {}".format(test_case,s))