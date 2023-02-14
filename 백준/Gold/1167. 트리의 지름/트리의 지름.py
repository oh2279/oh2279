import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(now,parent):
  for next, weight in tree[now]:
    if dist[next]==0 and next != parent:
      dist[next] = dist[now]+weight
      dfs(next,now)

if __name__ == "__main__":
  v = int(input())
  tree = [[] for _ in range(v+1)]
  dist = [0 for _ in range(v+1)]
  
  for _ in range(v):
    arr = input()
    info = list(map(int, arr.split()[:-1]))
    node = info[0]
    for i in range(1,len(info),2):
      tree[node].append([info[i],info[i+1]])
  
  dfs(1,0) 
  point1 = max(range(1,v+1), key = lambda i : dist[i]) # 지름이 될 수 있는 한 점
  
  dist = [0 for _ in range(v+1)]
  
  point2 = dfs(point1,0) # 지름을 완성하는 두번째 점
  #print(dist)
  print(max(dist))