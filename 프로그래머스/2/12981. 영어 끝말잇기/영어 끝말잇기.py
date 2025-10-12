import math
def solution(n, words):
    answer = []
    num, order = 0,0
    for i in range(1, len(words)):
        if words[i-1][-1] != words[i][0] or words[i] in words[:i]: # 끝말이 아닐 경우 + 중복일 경우
            num = (i) % n +1
            order = (i//n) + 1
            break
            
    answer = [num,order]
    return answer