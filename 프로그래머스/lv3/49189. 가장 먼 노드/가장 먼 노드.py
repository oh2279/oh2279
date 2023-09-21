from collections import deque

def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n+1)]
    visited = [False] *(n+1)
    dist = [0] * (n+1)
    q = deque()
    
    for start, end in edge:
        graph[start].append(end)
        graph[end].append(start)
    
    visited[1]=True
    dist[1] = 0
    q.append(1)

    while q:
        now = q.popleft()
        for next in graph[now]:
            cost = dist[now] + 1
            if not visited[next]:
                dist[next]=dist[now]+1
                q.append(next)
                visited[next] =True
    
    answer = dist.count(max(dist))
    return answer