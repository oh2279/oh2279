input = __import__('sys').stdin.readline

sum = int(input())

i = 1

while True:
    sum = sum - i
    if sum <= i:
        break
    i+=1
print(i)