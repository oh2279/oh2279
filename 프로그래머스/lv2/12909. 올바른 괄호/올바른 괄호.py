def solution(s):
    answer = True
    
    stack = []
    
    for now in s:
        if now =='(':
            stack.append('(')
        elif now == ')':
            if len(stack)==0:
                answer = False
            else:
                stack.pop()
                
    if len(stack) != 0:
        answer = False

    return answer