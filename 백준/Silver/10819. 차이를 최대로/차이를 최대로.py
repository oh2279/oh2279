import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def main():  
  dfs(0)
  
  print(ans)
  
def dfs(depth):
  global tmp
  
  if depth == n:
    calc()
    return
  
  for i in range(n):
    if not visited[i]:
      visited[i] = True
      tmp.append(numbers[i])
      dfs(depth+1)
      tmp.pop()
      visited[i] = False
    
def calc():
  global ans
  sum = 0
  for i in range(len(tmp)-1):
    sum += abs(tmp[i]-tmp[i+1])
    
  ans = max(sum,ans)
  
if __name__ == "__main__":
  n = int(input())
  numbers = list(map(int, input().split()))
  visited = [False for _ in range(n)]
  tmp = []
  ans = -1e9
  main()