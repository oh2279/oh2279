import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def main():  
  dfs(1,numbers[0])
  
  print(int(max_ans),int(min_ans), sep='\n')
  
def dfs(depth,num):
  global add, sub, mul, div, max_ans, min_ans
  
  if depth == n:
      max_ans = max(max_ans,num)
      min_ans = min(min_ans,num)
    
  else:
    if add > 0:
        add -= 1
        dfs(depth+1,num + numbers[depth])
        add+=1
      
    if sub > 0:
        sub -= 1
        dfs(depth+1,num - numbers[depth])
        sub+=1
      
    if mul > 0:
        mul -= 1
        dfs(depth+1,num * numbers[depth])
        mul+=1
      
    if div > 0:
        div -= 1
        dfs(depth+1, int(num / numbers[depth]))
        #dfs(depth+1, num // numbers[depth])
        div+=1
      
  
if __name__ == "__main__":
  n = int(input())
  numbers = list(map(int, input().split()))
  add, sub, mul, div = map(int, input().split())
  
  max_ans = -1e9
  min_ans = 1e9

  main()