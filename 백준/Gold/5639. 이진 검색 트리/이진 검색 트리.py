import sys
#from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def postorder(start, end):
    if start >= end: 
        if start == end:
            print(tree[end])
        return
    
    mid = end+1
    
    for i in range(start+1,end+1):
        if tree[i] > tree[start]:
            mid = i
            break
        
    postorder(start+1,mid-1)
    postorder(mid,end)
    print(tree[start])

if __name__ == "__main__":
    tree = []
    
    while True:
        try:
            tree.append(int(input()))
        except:break
        
    postorder(0,len(tree)-1)