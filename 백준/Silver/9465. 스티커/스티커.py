import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

if __name__ == "__main__":
  t = int(input())
  
  for _ in range(t):
    n = int(input())
    
    sticker = []
    
    for i in range(2):
      sticker.append(list(map(int, input().split())))
      
    if n == 1:
      print(max(sticker[0][0],sticker[1][0]))
    else:
      sticker[0][1] += sticker[1][0]
      sticker[1][1] += sticker[0][0]
      
      for i in range(2,n):
        sticker[0][i] += max(sticker[1][i-1],sticker[1][i-2])
        sticker[1][i] += max(sticker[0][i-1],sticker[0][i-2])
        
      max_value = max(map(max, sticker))
      print(max_value)