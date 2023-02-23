T = input()
P = input()
temp = [0 for _ in range(len(T))]


ii = 0

for j in range(1,len(P)):
    while ii > 0 and  P[ii]!= P[j]:
        ii = temp[ii-1]
    if P[ii] == P[j]:
        ii+=1
        temp[j] = ii;
result = []
i =0
for j in range(len(T)):
    while i> 0 and P[i]!= T[j]:
        i = temp[i-1]
    if P[i] == T[j]:
        if i == (len(P)-1):
            result.append(j-i+1)
            i = temp[i]
        else:
            i+=1
print(len(result))
for r in result:
    print(r,end=' ')
print()

