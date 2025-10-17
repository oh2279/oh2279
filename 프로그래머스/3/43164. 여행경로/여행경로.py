def dfs(start, depth):
    if depth == n:
        answer[:] = tmp[:]        # 완성 경로 복사
        return True               # 🔴 조기 종료 신호

    for i in range(n):
        a, b = tickets[i]
        if not visited[i] and a == start:
            visited[i] = True
            tmp.append(b)
            if dfs(b, depth + 1): # 🔴 완성되면 위로 True 전파
                return True
            tmp.pop()
            visited[i] = False
    return False

def solution(tickets_input):
    global tickets, visited, n, tmp, answer
    tickets = sorted(tickets_input, key=lambda x: (x[0], x[1]))  # 사전순
    n = len(tickets)
    visited = [False]*n
    tmp = ['ICN']
    answer = []

    dfs('ICN', 0)  # 🔴 첫 완성에서 멈춤
    return answer