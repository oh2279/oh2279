import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline
from collections import deque

def main():  
  print(bfs())
  
def bfs():
  ans = 0
  while len(q) > 0 :
    ord = q.popleft()
    pos = ord[0]
    cnt = ord[1]
    
    visited[pos]= True
        
    if pos == k:
      ans = cnt
      break
    
    if pos*2 >= 0 and pos*2 < 100001 and not visited[pos*2]:
      q.append([ pos *2, cnt ])

    if pos-1 >= 0 and pos-1 < 100001 and not visited[pos-1]:
      q.append([pos - 1, cnt + 1 ])
        
    if pos+1 >= 0 and pos+1 < 100001 and not visited[pos+1]:
      q.append([ pos + 1, cnt + 1 ])
      
    
  return ans
  
if __name__ == "__main__":
  n,k = map(int,input().split())
  q = deque()
  visited = [False] * 100010
  q.append([n,0])
  
  main()