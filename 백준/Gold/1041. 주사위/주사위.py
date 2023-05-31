import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    ans = 0
    dice = list(map(int,input().split()))
    
    if N == 1:
        print(sum(dice)-max(dice))
    else: # N >= 2
        
        # 제일 작은 수  3개 고르는데, 주사위의 특성 고려
        cube = [min(dice[0], dice[5]),
                min(dice[1], dice[4]),
                min(dice[2], dice[3])]
        cube.sort()

        # 한 면만 보이는 주사위
        ans += ((N-1) * 4 * (N-2) + (N-2)**2) * cube[0]
        
        # 두 면이 보이는 주사위
        ans += ((N-1) * 4 + (N**2-4-(N-2)**2)) * (cube[0] + cube[1])
        
        # 세 면이 보이는 주사위
        ans += 4 * sum(cube)
        
        print(ans)