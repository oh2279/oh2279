import sys
input = sys.stdin.readline

n = int(input().strip())
arr = [list(map(int, input().split())) for _ in range(n)]

# 차수 짝수 체크
for i in range(n):
    if sum(arr[i]) % 2 != 0:
        print(-1)
        sys.exit(0)

# 시작 정점(간선 있는 곳이 있으면 거기서)
start = 0
for i in range(n):
    if sum(arr[i]) > 0:
        start = i
        break

stack = [start]
answer = []
idx = [0]*n                 # 각 정점에서 '다음으로 볼 열' 포인터

while stack:
    node = stack[-1]

    # for대신 포인터를 남은 간선 있는 곳까지 전진
    while idx[node] < n and arr[node][idx[node]] == 0:
        idx[node] += 1

    if idx[node] == n:
        # 더 갈 간선 없음 → pop 시점에 기록
        answer.append(node + 1)   # 1-index
        stack.pop()
    else:
        nxt = idx[node]
        # 무방향 간선 소모(양쪽 감소)
        arr[node][nxt] -= 1
        arr[nxt][node] -= 1
        stack.append(nxt)

print(*answer[::-1])