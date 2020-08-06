def solution(progresses, speeds):
    
    list = []
    answer = []
    
    for i in range(len(progresses)):
        list.append((99-progresses[i])//speeds[i]+1)
        
    print(list)
    
    count = 0
    idx = 0
    for i in range(len(progresses)):
        if list[idx] >= list[i]:
            count += 1
        else:
            answer.append(count)
            idx = i
            count = 1
        
    answer.append(count) 
    
    return answer