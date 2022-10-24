import sys
input = sys.stdin.readline

n = int(input())
ans=[]
for _ in range(n):
    #arr=[]
    arr = list(map(int, input().split()))
    ans.append(arr)
    
ans.sort(key=lambda x: (x[1],x[0]))

for con in ans:
    print(con[0], con[1], end='\n')