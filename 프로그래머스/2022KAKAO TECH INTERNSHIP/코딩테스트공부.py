def solution(alp, cop, problems):
    #alp_req, cop_req, alp_rwd, cop_rwd, cost
    malp=0
    mcop = 0
    for a,b,c,d,e in problems:
        if malp<a:
            malp = a
        if mcop < b:
            mcop = b
    dp = [[1e9 for _ in range(malp+31)] for _ in range(mcop+31)]

    problems.append([0,0,1,0,1])
    problems.append([0,0,0,1,1])
    if alp>= malp:
        alp = malp
    if cop >= mcop:
        cop = mcop
    if alp>=malp and cop >=mcop:
        return 0
    dp[alp][cop] = 0
    for i in range(alp,malp+1):
        for j in range(cop,mcop+1):
            for a,b,c,d,e in problems:
                 if i >= a and j >= b:
                    k = i + c if i + c < malp else malp 
                    l = j + d if j + d < mcop else mcop
                    dp[k][l] = min([dp[k][l], dp[i][j] + e])
    answer = dp[malp][mcop]
    return answer