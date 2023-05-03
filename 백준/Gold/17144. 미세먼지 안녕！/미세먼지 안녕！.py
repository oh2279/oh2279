import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def clean():
    for i in range(first[0]-1,-1,-1): # ㅜ
        if board[i+1][0] == -1: board[i][0]=0
        else : board[i+1][0] = board[i][0]
        
    for i in range(1,c): # ㅓ
        board[0][i-1] = board[0][i]
    
    for i in range(1,first[0]+1): #ㅗ
        board[i-1][c-1] = board[i][c-1]
        
    for i in range(c-1,0,-1): # ㅏ
        if board[first[0]][i-1] == -1 : board[first[0]][i]=0
        else :board[first[0]][i] = board[first[0]][i-1]
    #------
    
    for i in range(second[0]+1,r): #ㅗ
        if board[i-1][0] == -1: board[i][0]=0
        else : board[i-1][0] = board[i][0]
        
    for i in range(1,c): #ㅓ
        board[r-1][i-1] = board[r-1][i]
    
    for i in range(r-1,second[0],-1): #ㅜ
        board[i][c-1] = board[i-1][c-1]
        
    for i in range(c-1,0,-1): #ㅏ
        if board[second[0]][i-1] == -1 : board[second[0]][i]=0
        else : board[second[0]][i] = board[second[0]][i-1]

def bfs():
    for _ in range(t):
        tmp_arr = [[0] * c for _ in range(r)]
        for x in range(r):
            for y in range(c):
                if board[x][y] > 0:
                    tmp = 0
                    for i in range(4):
                        nx = x + dx[i]
                        ny = y + dy[i]
                    
                        if nx <0 or ny <0 or nx >= r or ny >= c:
                            continue
                        if board[nx][ny] == -1: continue
                        
                        tmp_arr[nx][ny] += board[x][y] // 5
                        tmp += board[x][y] // 5
                    board[x][y] -= tmp
                    
        for i in range(r):
            for j in range(c):
                board[i][j] += tmp_arr[i][j]    
        
        clean()
        
    sum = 0
    for row in board:
        for data in row:
            if data != -1:
                sum += data
    return sum

if __name__ == "__main__":
    r,c,t = map(int,input().split())
    board = [[0]*c for _ in range(r)]

    first = [0,0]
    second = [0,0]
    
    for i in range(r):
        board[i] = list(map(int,input().split()))
        for j in range(len(board[i])):
            if board[i][j] == -1:
                if first==[0,0]:
                    first = [i,j]
                else: second = [i,j]
            
    print(bfs())