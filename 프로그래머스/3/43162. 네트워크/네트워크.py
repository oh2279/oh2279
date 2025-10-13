def dfs(now, visited, computers):
    visited[now] = True
    
    for next in range(len(computers[now])):
        if computers[now][next] == 1 and now != next and not visited[next]:
            dfs(next, visited, computers)
            
    return 0
            
def solution(n, computers):
    answer = 0
    visited = [False] * n
    
    for i in range(n):
        if not visited[i]:
            dfs(i, visited, computers)
            answer += 1
    
    return answer