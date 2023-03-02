import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

if __name__ == "__main__":
  n = int(input())
  numbers = [0] + list(map(int, input().split()))
  dp = [ [False for _ in range(n+1)] for _ in range(n+1)]
  
  
  for i in range(1,n+1): # [1,1] [2,2] 같은 경우는 항상 펠린드롬!
      dp[i][i]=True
      
  for i in range(1,n): # [1,2] 같은 경우 같으면 회문
      if numbers[i]== numbers[i+1] : dp[i][i+1]=True
  
  for cnt in range(1,n-1):
    for i in range(1, n-cnt):
      # [1,3] [2,5]같은 경우
      j = i+1+cnt
      if numbers[i] == numbers[j] and dp[i+1][j-1]:
        dp[i][j] = True
      
  m = int(input())
  for i in range(m):
    s,e = map(int, input().split())
    if dp[s][e]:
      print(1)
    else: print(0)