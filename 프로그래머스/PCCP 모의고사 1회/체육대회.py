from itertools import permutations
def solution(ability):
    answer = 0
    st = [i for i in range(len(ability))]
    stuNum = len(ability)
    kkNum = len(ability[0])
    ll = list(permutations(st,kkNum))
    summ = []


    for l in ll:
        s = 0
        for i in range(kkNum):
            s += ability[l[i]][i]
        summ.append(s)
    summ = sorted(summ)
    answer = summ[-1]
    return answer