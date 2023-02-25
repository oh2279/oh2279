import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def postfix(s):
  ans=''
  stack = deque()
  
  for i in range(len(s)):
    if s[i].isalpha():
      ans+=s[i]
    else:
      if s[i] =='(':
        stack.append(s[i])
      elif s[i] == '*' or s[i] == '/':
        while stack and (stack[-1] == '*' or stack[-1] =='/'):
          ans += stack.pop()
        stack.append(s[i])
      elif s[i] == '+' or s[i] == '-':
        while stack and stack[-1] != '(':
          ans += stack.pop()
        stack.append(s[i])
      elif s[i] == ')':
        while stack and stack[-1] != '(':
          ans += stack.pop()
        stack.pop()
      
  while stack :
    ans+=stack.pop()
  return ans

if __name__ == "__main__":
  s = input()
  print(postfix(s))