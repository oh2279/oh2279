import sys

def binary_search(arr, num,left,right):
    
    while left <= right:
        mid = int((left + right) /2)
        
        if arr[mid]==num:
            return True
        
        elif arr[mid] < num:
            left = mid +1
        else :
            right = mid -1
    
    return False


n = int(input())
card  =list(map(int, sys.stdin.readline().split()))

m = int(input())
cmp  = list(map(int, sys.stdin.readline().split()))
card = sorted(card)

for i in cmp:
    if binary_search(card, i,0,n-1):
        print(1, end= ' ')
    else:
        print(0, end=' ')
