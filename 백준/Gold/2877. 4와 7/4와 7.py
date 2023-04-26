import sys
#from collections import deque
#sys.setrecursionlimit(10**6)
from collections import Counter
input = sys.stdin.readline

if __name__ == "__main__":
    k = bin(int(input())+1)
    ans = ""

    for i in range(k.find('b')+2,len(k)):
        if k[i] == '0':
            ans += '4'
        elif k[i] == '1':
            ans += '7'
            
    print(ans)