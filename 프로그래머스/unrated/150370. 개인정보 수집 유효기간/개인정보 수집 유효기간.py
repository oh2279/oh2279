def solution(today, terms, privacies):
    answer = []
    nyear = int(today[:4])
    nmonth = int(today[5:7])
    nday = int(today[8:])
    
    for i in range(len(terms)):
        for j in range(len(privacies)):
            if terms[i][0] == privacies[j][-1]:
                year = int(privacies[j][:4])
                month = int(privacies[j][5:7]) + int(terms[i][2:])
                day = int(privacies[j][8:10]) - 1
                
                while month > 12:
                    month -= 12
                    year += 1
                if day <= 0:
                    day = 28
                    month -= 1
                    if month <= 0:
                        month = 12
                        year -= 1
                if nyear > year:
                    answer.append(j+1)
                elif nyear == year:
                    if nmonth > month:
                        answer.append(j+1)
                    elif nmonth == month:
                        if nday > day:
                            answer.append(j+1)
    answer.sort()                                  
    return answer