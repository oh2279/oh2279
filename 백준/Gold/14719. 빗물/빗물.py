import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

if __name__ == "__main__":
    h,w = map(int,input().split())
    
    blocks = list(map(int, input().split()))
    
    ans = 0
    
    for i in range(1,w-1):
        # 현위치 기준 좌우측에서 가증 큰 값
        left_max = max(blocks[:i])
        right_max = max(blocks[i+1:])

        cmp = min(left_max, right_max) # 그중 작은 값 만큼만 최대 물이 찰 수 있음

        if cmp > blocks[i]:
            ans += (cmp - blocks[i]) # 자기 자신을 뺀 만큼만 물이 참
    print(ans)