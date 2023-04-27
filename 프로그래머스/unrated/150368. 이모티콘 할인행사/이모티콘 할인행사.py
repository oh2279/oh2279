answer = [0,0]
def solution(users, emoticons):
    n = len(users)
    m = len(emoticons)
    sale_percent = [40,30,20,10]
    sale_board = [0] * m
    def dfs(idx):
        global answer
        
        def cal():
            cnt = 0; sale_money=0;
            for i in range(n): # 유저 별로
                money = 0
                for j in range(m): # 이모티콘 별
                    if users[i][0] <= sale_board[j]: # 만약 유저의 구매 기준이 할인율 보다 높다면
                        money += emoticons[j] * ((100-sale_board[j])/100) # 구매
                        if money >= users[i][1]: # 만약 구매 시, 비용을 초과한다면
                            cnt += 1 # 이모플 가입자 +1
                            money = 0
                            break
                sale_money += money

            return [cnt, sale_money]
        
        if idx == m:
            tmp = cal()
            if tmp[0] > answer[0] : answer = tmp
            elif tmp[0] == answer[0]:
                if tmp[1] > answer[1]:
                    answer = tmp   
            return

        for i in range(4):
            sale_board[idx] = sale_percent[i]
            dfs(idx+1)
    
    dfs(0)

    return answer
