import sys
import heapq
input = sys.stdin.readline

def topology_sort():
    while heap:
        num = heapq.heappop(heap)
        for i in graph[num]:
            inDegree[i] -= 1
            if inDegree[i] == 0:
                heapq.heappush(heap,i)
        print(num, end = ' ')
        
    

n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
arr=[]
heap =[]
inDegree = [0 for _ in range(n+1)]

for _ in range(m):
    big, small = map(int, input().split())
    arr.append((big,small))
    
for big,small in arr:
    inDegree[small]+=1
    graph[big].append(small)
    
for i in range(1, n + 1):
    if inDegree[i] == 0:
        heapq.heappush(heap,i)
    
topology_sort()
    