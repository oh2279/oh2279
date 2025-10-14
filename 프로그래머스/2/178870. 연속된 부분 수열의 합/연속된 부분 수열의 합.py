def solution(sequence, k):
    answer = []
    num = 0
    mini = 1e+9
    end_idx = len(sequence)-1
    for i in range(len(sequence)-1, -1, -1):
        num += sequence[i]
        if num > k:
            num -= sequence.pop()
            end_idx = len(sequence)-1
        #print(sequence,num)
        if num == k:
            start_idx = i 
            if abs(end_idx - start_idx) <= mini:
                answer=[start_idx , end_idx]
                mini = abs(end_idx - start_idx)
            
    return answer