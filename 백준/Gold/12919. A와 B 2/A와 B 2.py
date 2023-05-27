import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(s,t):
    if s==t:
        return 1
    
    if len(t)<=len(s):
        return 0
    
    ans = 0
    if t[-1] == 'A': # 마지막이 A면 그냥 제거
        ans = dfs(s,t[:-1])
    if ans == 1:
        return 1

    if t[0]=='B': # 처음이 B면 reverse 후 제거
        ans = dfs(s,t[::-1][:-1])
        
    return ans

if __name__ == "__main__":
    S = list(input().rstrip())
    T = list(input().rstrip())
 
    print(dfs(S,T))