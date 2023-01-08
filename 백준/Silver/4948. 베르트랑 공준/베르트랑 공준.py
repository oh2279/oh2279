import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

all = list(range(2, 246912))
arr = []

for i in all:
    if isPrime(i):
        arr.append(i)

while True:
    n = int(input())
    ans = 0
    if n == 0:
        break
    for i in arr:
        if n < i <= 2*n:
            ans += 1
    print(ans)
