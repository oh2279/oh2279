import math
def solution(n, words):
    answer = []
    result = []
    num, order = 0,0
    for idx, word in enumerate(words):
        if word in result: # 중복 검사
            order = math.ceil((idx+1)/n)
            num = (idx+1) % n 
            if num == 0: num = n
            break
        elif len(result) != 0: # 중복은 아니지만 다른 단어
            last_word = result[-1]
            if last_word[-1] != word[0]:
                #print(last_word, word)
                num = (idx+1) % n 
                if num == 0: num = n
                order = math.ceil((idx+1) / n)
                break
        result.append(word)
         
    answer = [num,order]
    return answer