import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
arr=[]
cnt = -1
ans = 0

for i in range(n):
    p, d = map(int,input().split())
    arr.append([p,d])
    cnt = max(cnt,d)
    
arr = sorted(arr,key=lambda x:-x[0])
visited = [0 for _ in range(cnt+1)]

for p,d in arr:
    if visited[d]==0:
        visited[d] = p
    else:
        d-=1
        while d:
            if visited[d]==0:
                visited[d] = p
                break
            d -= 1
            
for w in visited:
    ans += w

print(ans)