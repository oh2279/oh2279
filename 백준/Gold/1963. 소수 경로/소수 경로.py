import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def primeNumber():
    for i  in range(2, 10000):
        if pNum[i]:
            if i >= 1000:
                primes.append(i)
            for j in range(2*i, 10000, i):
                pNum[j] = False
        
def game_rule(a,b):
    cnt=0
    a = str(a)
    b = str(b)
    for i in range(4):
        if a[i] != b[i]:
            cnt += 1
    if cnt == 1:
        return True
    return False

def bfs():
    q=deque()
    visited = [False] * 10000
    
    q.append([p1,0])
    visited[p1] = True
    
    while q:
        now,mov = q.popleft()
        
        if now == p2:
            return mov
        
        for next in primes:
            if not visited[next] and game_rule(now,next):
                q.append([next,mov+1])
                visited[next] = True
    
    return -1
if __name__ == "__main__":
    t = int(input())
    
    pNum = [False, False] + [True] * 9998
    primes=[]
    primeNumber()
    
    for _ in range(t):
        p1, p2 = map(int,input().split())
        res = bfs()
        if res == -1: print('Impossible')
        else : print(res)