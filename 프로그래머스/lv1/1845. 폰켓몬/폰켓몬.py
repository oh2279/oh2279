def solution(nums):
    answer = 0
    dict = {}
    can_get = len(nums)//2
    
    for num in nums:
        if num in dict:
            dict[num] = dict[num]+1
        else:
            dict[num]=1
            
    answer = len(dict)
    if len(dict) > can_get:
        answer = can_get
    return answer