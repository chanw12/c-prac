n = int(input())


a = [False,False] + [True]*(n-1)

primes=[]

for i in range(2,n+1):
  if a[i]:
    primes.append(i)
    for j in range(2*i, n+1, i):
        a[j] = False

ll = primes



cnt = 0
end = 0
summ = 0
for i in range(len(ll)):
    while summ < n and end < len(ll):
        summ += ll[end]
        end += 1
    if summ == n:
        cnt +=1
    summ -= ll[i]
print(cnt)