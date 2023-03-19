import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline
    
def prime_number():
    cnt =0
    
    for i in range(2,n+1):
        if numbers[i]:
            numbers[i] = False
            cnt += 1
            if cnt == k:
                return i
            for j in range(2*i, n+1,i):
                if numbers[j]:
                    numbers[j] = False
                    cnt +=1
                    if cnt == k:
                        return j
                

if __name__ == "__main__":
    n,k = map(int, input().split())
    
    numbers = [True] * (n+1)
    
    print(prime_number())