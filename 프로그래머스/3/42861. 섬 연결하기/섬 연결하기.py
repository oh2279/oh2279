def find(parent,x):
    if parent[x]!=x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent,a,b):
    a = find(parent,a)
    b = find(parent,b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
    return parent

def solution(n, costs):
    answer = 0
    parent=[0]*(n+1)
    costs.sort(key = lambda x : x[2])
    for i in range(1,n+1):
        parent[i]=i
        
    for v in costs:
        a,b,cost = v
        if find(parent,a) != find(parent,b):
            parent = union(parent,a,b)
            answer += cost
    
    return answer