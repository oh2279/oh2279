import sys
input = sys.stdin.readline

arr = list(input().strip())
bomb = list(input().strip())
bomb_siz = len(bomb)
answer = []

same=False
for i in range(len(arr)):
    answer.append(arr[i])
    
    if len(answer) >= len(bomb):
        same = True
        for j in range(len(bomb)):
            if answer[-len(bomb) + j] != bomb[j] :
                same = False
                break
        
        if same:
            for j in range(len(bomb)):
                answer.pop(-1)
            
if len(answer)==0:
    print("FRULA")
else:
    print("".join(answer))