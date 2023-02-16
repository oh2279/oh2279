import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def factorial():
  arr = [0] * 101
  arr[1] = 1
  for i in range(2,101):
    arr[i] = i * arr[i-1]
  return arr
if __name__ == "__main__":
  f_arr = factorial()
  n,m = map(int,input().split())
  
  print(f_arr[n] // (f_arr[n-m] * (f_arr[m])))