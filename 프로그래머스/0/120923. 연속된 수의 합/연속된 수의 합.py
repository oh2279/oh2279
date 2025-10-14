def solution(num, total):
    d = 0
    for i in range(1,num):
        d += i
    first = (total-d) / num
    answer= [first + i for i in range(num)]
    return answer