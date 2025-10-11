from itertools import combinations

n, k = map(int, input().split())
arr = []
result = 1e+8

for _ in range(n):
    arr.append(list(map(int, input().split())))

def calc(combs):
    new_arr = [x for x in arr if x not in combs]
    answer = []
    for h in new_arr:
        dist = 1e+8
        for c in combs:
            dist = min(dist, abs(c[0]-h[0]) + abs(c[1]-h[1]))
        answer.append(dist)
    return max(answer)

for c in combinations(arr, k):
    result = min(result, calc(c))
    
print(result)
        
        