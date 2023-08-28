from collections import deque
def solution(numbers, target):
    answer = 0

    q = deque()
    q.append([numbers[0],0])
    q.append([-1*numbers[0],0])
    n = len(numbers)
    
    while q:
        number,idx = q.popleft()
        idx = idx + 1
        
        if idx < n:
            q.append([number + numbers[idx],idx])
            q.append([number - numbers[idx],idx])
            
        else:
            if number == target:
                answer = answer + 1
            
    return answer