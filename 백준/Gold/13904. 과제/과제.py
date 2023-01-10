import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
arr=[]
cnt = -1
ans = 0

for i in range(n):
    d,w = map(int,input().split())
    arr.append([d,w])
    cnt = max(cnt,d)
    
arr = sorted(arr,key=lambda x:-x[1])
visited = [0 for _ in range(cnt+1)]

for day,weight in arr:
    if visited[day]==0:
        visited[day] = weight
    else:
        day-=1
        while day:
            if visited[day]==0:
                visited[day] = weight
                break
            day -= 1
            
for w in visited:
    ans += w

print(ans)