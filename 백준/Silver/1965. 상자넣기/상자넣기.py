import sys
#from collections import deque
#import heapq
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

if __name__ == "__main__":
  n = int(input())
  boxes = list(map(int, input().split()))
  
  dp = [1 for _ in range(n)]

  for i in range(n):
      for j in range(i):
          if boxes[i] > boxes[j]:
              dp[i] = max(dp[i], dp[j]+1)

  print(max(dp))