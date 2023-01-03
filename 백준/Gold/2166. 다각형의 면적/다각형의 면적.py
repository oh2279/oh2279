import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def shoelace():
    idx_y = 1
    idx_x = 1
    ans = 0
    for i in range(len(locate)-1):
        ans += (locate[i][0] * locate[idx_y][1])
        idx_y += 1
    ans += locate[-1][0] * locate[0][1]
    
    for i in range(len(locate)-1):
        ans -= (locate[idx_x][0] * locate[i][1])
        idx_x += 1
    ans -= locate[0][0] * locate[-1][1]
    
    print(abs(ans) / 2)

n = int(input())
locate =[]

for _ in range(n):
    x, y = map(int,input().split())
    locate.append([x,y])

shoelace()