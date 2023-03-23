import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def ccw():
    return (x1*y2+x2*y3+x3*y1) - (x2*y1+x3*y2+x1*y3)
if __name__ == "__main__":
    x1, y1 = map(int,input().split())
    x2, y2 = map(int,input().split())
    x3, y3 = map(int,input().split())
    
    ans = ccw()
    if ans > 0 : print(1) # 반시계
    elif ans < 0: print(-1) # 시계
    else: print(0)