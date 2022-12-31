import sys
from collections import deque
input = sys.stdin.readline

def topology_sort():
    while q:
        num = q.popleft()
        for i in graph[num]:
            inDegree[i] -= 1
            if inDegree[i] == 0:
                q.append(i)
        print(num, end = ' ')
        
    

n,m = map(int,input().split())
graph = [[] for _ in range(32001)]
arr=[]
inDegree = [0 for _ in range(32001)]
q = deque()

for _ in range(m):
    big, small = map(int, input().split())
    arr.append((big,small))
    
for big,small in arr:
    inDegree[small]+=1
    graph[big].append(small)
    
for i in range(1, n + 1):
    if inDegree[i] == 0:
        q.append(i)
    
topology_sort()
    