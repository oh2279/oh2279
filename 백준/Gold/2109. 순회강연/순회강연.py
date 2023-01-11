import sys
import heapq    
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
arr=[]

for i in range(n):
    arr.append(list(map(int,input().split())))
    
arr = sorted(arr,key=lambda x:x[1])

schedule=[]
for i in arr:
  heapq.heappush(schedule, i[0])
  if (len(schedule)>i[1]):
    heapq.heappop(schedule)

print(sum(schedule))