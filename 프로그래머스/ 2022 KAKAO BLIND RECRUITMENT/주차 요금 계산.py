
import math
def solution(fees, records):
    answer = {}
    helo = {}
    for record in records:
        time,number,ttype = record.split()
        answer[number] = 0
    b_time,b_fee,u_time,u_fee = fees
    for record in records:
        time,number,ttype = record.split()
        hh,mm = time.split(":")
        time = int(hh)*60 + int(mm)
        if ttype == "IN":
            helo[number] = int(time)
        if ttype == "OUT":
            inputtime = helo[number]
            if number in answer:
                answer[number] += time-inputtime
            del helo[number]
    for h in helo:
        time = 23*60 +59
        inputtime= int(helo[h])
        answer[h] += time - inputtime

    tempp = []
    for a in answer:
        money = 0
        if answer[a] > b_time:
            answer[a] -= b_time
            money += b_fee
            while answer[a] >0:
                answer[a] -=u_time
                money += u_fee
        else:
            money = b_fee
        
        tempp.append([int(a),money])   
    
    tempp = sorted(tempp)
    ttt = []
    for i in tempp:
        ttt.append(i[1])
    return ttt