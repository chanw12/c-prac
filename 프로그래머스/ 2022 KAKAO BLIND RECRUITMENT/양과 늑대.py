def solution(info, edges):
    answer = []

    visited  = [False for _ in range(len(info))]
    visited[0] = True
    def dfs(sheep,wolf):
        if sheep <=wolf:
            return
        else:
            answer.append(sheep)
        
        for a,b in edges:
            if visited[a] and not visited[b]:
                visited[b] = True
                if info[b] == 0:
                    dfs(sheep+1,wolf)
                else:
                    dfs(sheep,wolf+1)
                visited[b] = False
      
    dfs(1,0)
        
    return max(answer)