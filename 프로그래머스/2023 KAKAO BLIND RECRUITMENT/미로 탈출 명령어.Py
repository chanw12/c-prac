
da = [-1,0,0,1]
db= [0,1,-1,0]
dd = ["u","r","l","d"]
answer = []
# d l r u
def solution(n, m, x, y, r, c, k):
    ll = abs(x-r)+ abs(y-c)
    answer = ''
    if ll%2 != k%2 or ll >k:
        return "impossible"
    
    st = []
    st.append((x,y,''))
    
    while st:
        a,b,s = st.pop()
        if a == r and b == c and len(s) == k:
            answer = s
            break
        for i in range(4):
            na = a+da[i]
            nb = b + db[i]
            ns = s+dd[i]
            if abs(na - r) + abs(nb - c) + len(s) + 1 > k:
                continue
            if na>0 and na<=n and nb>0 and nb<=m:
                st.append((na,nb,ns))

        
    return answer


        