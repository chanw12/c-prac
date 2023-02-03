def solution(today, terms, privacies):
    answer = []
    term = {}
    for i in terms:
        a,b = i.split(" ")
        term[a] = b
    
    
    for i in range(len(privacies)):
        date, val = privacies[i].split(" ")
        year,month,day = map(int,date.split("."))
        cyear,cmonth,cday = map(int,today.split("."))
        
        datetime = year * (12*28) + month*28 + day + int(term[val]) * 28 -1
        cdatetime = cyear * (12*28) + cmonth*28 +cday

        if cdatetime > datetime:
            answer.append(i+1)
        
        

    return answer