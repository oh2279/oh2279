def solution(t, p):
    answer = 0
    flag = False
    siz = len(p)
    arr=[]
    
    for i in range(len(t)-(siz-1)):
        arr.append(t[i:i+siz])
      
    for i in range(len(arr)):
        if int(arr[i]) <= int(p):
            answer+=1
            
             
    return answer