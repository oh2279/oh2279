import sys
import math
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

d = [0 for i in range(10001)]
sn = [False for i in range(20000)]

for i in range(1,10001):
  num = i
  s = str(i)
  for j in range(len(s)):
    num+=int(s[j])
  d[i] = num

for i in range(1,10001):
  num = d[i]
  sn[num]= True
  
for i in range(1,10001):
  if sn[i]==False:
    print(i)