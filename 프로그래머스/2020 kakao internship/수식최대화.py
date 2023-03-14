from itertools import permutations
def solution(expression):
    answer = []
    ll = ['+','-','*']
    l = list(permutations(ll))
    
    
    for i in l:
        a = expression.split(i[0])
        
        b = [x.split(i[1]) for x in a]
        
        c = [[str(eval(x)) for x in temp] for temp in b]
        
        c = [str(eval(i[1].join(temp))) for temp in c]
        c = abs(eval(i[0].join(c)))
        answer.append(c)
        
            
            
    
    return max(answer)