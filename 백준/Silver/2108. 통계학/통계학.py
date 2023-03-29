import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
from collections import Counter
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    
    arr=[]

    for _ in range(n):
        num = int(input())
        arr.append(num)
        
    arr.sort()

    if n>=2:
        modes = Counter(arr).most_common(2)
        
        if modes[0][1] == modes[1][1]:
            mode = modes[1][0]
        else:
            mode = modes[0][0]
    else: #n==1
        mode = arr[0]
    
    total = round(sum(arr)/(n*1.0))
    
    mid = n//2
    middle = arr[mid]

    arrange = abs(arr[0]-arr[-1])
    
    print(total, middle, mode, arrange, sep='\n')