from collections import Counter
def solution(input_string):
    answer = []
    print(input_string)
    temp = Counter(input_string)
    for i in temp:
        if temp[i] > 1:
            index = -1
            pre = -1
            while True:
                index= input_string.find(i,index+1)
                if index == -1:
                    break
                
                print('start=%d' % index)
                if pre != -1 and index - pre != 1:
                    answer.append(i)
                    break
                pre = index
    if len(answer) == 0:
        answer = 'N'
    else:
        answer = sorted(answer)
        answer = ''.join(answer)
    print(answer)

    return answer