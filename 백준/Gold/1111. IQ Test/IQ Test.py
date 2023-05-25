import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def get_A(i):
    if numbers[i]-numbers[i-1] == 0: return 1
    return int((numbers[i+1]-numbers[i]) / (numbers[i]-numbers[i-1])) # 기울기 공식 f(a)-f(b) / a-b

def get_B(i,a):
    return int(numbers[i] - a * numbers[i-1]) # y절편

def isEqual(x):
    return len(set(x)) <= 1

if __name__ == "__main__":
    N = int(input())
    numbers = list(map(int, input().split()))
    
    if N == 1: print('A')
    elif N == 2:
        if numbers[0] == numbers[1]: print(numbers[1])
        else:
            print('A')
    else: # N==3
        if isEqual(numbers):
            print(numbers[0])
            
        else:
            for i in range(1,N-1):
                a = get_A(i)
                b = get_B(i,a)
                end = False
                flag = True
                for idx in range(1,N):
                    if numbers[idx] != (numbers[idx-1] * a + b) :
                        flag = False
                        break
                    
                if flag:
                    print(int(numbers[-1] * a + b))
                    end = True
                    break
            if not end: print('B')