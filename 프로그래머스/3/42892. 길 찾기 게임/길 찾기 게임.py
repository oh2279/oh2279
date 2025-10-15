import sys
sys.setrecursionlimit(10**6)

def insert(parent, child):
    if child.x < parent.x:
        if parent.left is None:
            parent.left = child
        else:
            insert(parent.left, child)
    else:
        if parent.right is None:
            parent.right = child
        else:
            insert(parent.right, child)

class Node:
    def __init__(self, x, y, idx):
        self.x = x
        self.y = y
        self.idx = idx
        self.left = None
        self.right = None

def preorder(node, result):
    if not node: return result
    result.append(node.idx)
    preorder(node.left, result)
    preorder(node.right, result)
    return result

def postorder(node, result):
    if not node: return result
    postorder(node.left, result)
    postorder(node.right, result)
    result.append(node.idx)
    return result
    

def solution(nodeinfo):
    answer = []
    
    nodes = [Node(x, y, i+1) for i, (x, y) in enumerate(nodeinfo)]

    nodes.sort(key=lambda n: (-n.y, n.x))
    
    root = nodes[0]
    for nd in nodes[1:]:
        insert(root, nd)
    
    answer.append(preorder(root,[]))
    answer.append(postorder(root,[]))
    
    return answer