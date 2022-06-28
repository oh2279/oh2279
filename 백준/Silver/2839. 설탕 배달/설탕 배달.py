sugar = int(input())
ans = sugar
cnt = 0
flag = 0
while (ans % 5 != 0):
    ans = ans - 3
    cnt += 1
    if ans <0:
        cnt = -1
        break
    elif ans == 0:
        flag = 1
        break
if cnt == -1:
    print(-1)
else:
    if flag == 0:
        ans = ans // 5
        print(cnt + ans)
    elif flag == 1:
        print(cnt)