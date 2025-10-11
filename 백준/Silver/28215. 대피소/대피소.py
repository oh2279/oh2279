from itertools import combinations
INF  = float("INF")  #key point
n, k = map(int, input().split())
arr = []
result = INF

for _ in range(n):
    arr.append(list(map(int, input().split())))

def calc(combs):
    new_arr = [x for x in arr if x not in combs]
    rst = 0
    for h in new_arr:
        dist = INF
        for c in combs:
            dist = min(dist, abs(c[0]-h[0]) + abs(c[1]-h[1]))
        rst = max(rst, dist)
    return rst

for c in combinations(arr, k):
    result = min(result, calc(c))
    
print(result)
        
        