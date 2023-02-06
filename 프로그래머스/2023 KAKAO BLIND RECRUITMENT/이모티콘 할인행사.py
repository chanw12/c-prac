from itertools import product
def solution(users, emoticons):
    answer = []
    h = [10,20,30,40]
    temp = [[] for _ in range(len(emoticons))]
    result = []
    for i in range(len(emoticons)):
        for j in range(4):
            temp[i].append((emoticons[i],h[j]))
    
    ll = list(product(*temp))
    for i in range(len(ll)):
        n = 0
        s= 0 
        for k in range(len(users)):
            u_temp = 0
            u_discount,u_price = users[k]
            for j in range(len(ll[i])):
                price,discount = ll[i][j]
                if u_discount <= discount:
                    u_temp += price * (100-discount)/100
            if u_temp >= u_price:
                n+=1
            else:
                s += u_temp 
        result.append([n,s])

    result = sorted(result,key = lambda x:(-x[0],-x[1]))
    answer =result[0]
    return answer