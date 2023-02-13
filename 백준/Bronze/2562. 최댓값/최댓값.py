import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def get_max():
  pivot,idx= arr[0],0
  for i in range(1,9):
    if arr[i] >= pivot:
      pivot,idx = arr[i],i
  
  return pivot, idx+1

if __name__ == "__main__":
  arr=[]
  for _ in range(9):
    arr.append(int(input()))
    
  ans, idx = get_max()
  print(ans,idx ,sep='\n')