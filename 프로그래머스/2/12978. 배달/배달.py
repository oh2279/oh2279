import heapq
def solution(N, road, K):
    answer = 0

    maps = [[] for _ in range(N+1)]
    for r in road:
        s, e, c = r
        maps[s].append([e,c])
        maps[e].append([s,c])
    
    distance = [1e+9] * (N+1)
    
    q = []
    heapq.heappush(q, (0,1)) # cost, start
    distance[1] = 0
    
    while q:
        cost, now = heapq.heappop(q)
        for node in maps[now]:
            ncost = cost + node[1]
            next = node[0]
            if distance[now] < cost:
                continue
            if ncost < distance[next]:
                heapq.heappush(q, (ncost,next))
                distance[next] = ncost
                
    answer = len([dis for dis in distance[1:] if dis <= K])

    return answer