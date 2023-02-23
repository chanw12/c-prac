import heapq
def solution(n, paths, gates, summits):
    answer = []
    summits = set(summits)
    gates = set(gates)
    temp = [[] for _ in range(n+1)]
    for i in paths:
        temp[i[0]].append([i[1],i[2]])
        temp[i[1]].append([i[0],i[2]])
    inten = [1e9 for _ in range(n+1)]
    def dijk():
        q =[]
        for g in gates:
             heapq.heappush(q,(0,g))
        while q:
            intensity,cur = heapq.heappop(q)
            if intensity > inten[cur]:
                continue
            if cur in summits:
                continue
            for i in temp[cur]:
                if i[0] in gates:
                    continue
                nxt = i[0]
                nxtinten = max(i[1],intensity)
                if nxtinten < inten[nxt]:
                    inten[nxt] = nxtinten
                    heapq.heappush(q,(nxtinten,nxt))                    
    dijk()
    for s in summits:
        answer.append((s,inten[s]))
    answer = sorted(answer,key = lambda x:(x[1],x[0]))
    return answer[0]




#  List 자료형에서는 in 연산자의 시간 복잡도는 O(n) 이지만
# set이나 dict 자료형에서는 in 연산자의 시간 복잡도는 O(1)
#  게속 마지막 tc에서 시간초과가 발생해서 시간복잡도를 줄이기 위해 알아보던중 알게되었다.
#  
