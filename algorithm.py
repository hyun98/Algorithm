import heapq

def solution(lines):
    answer = 0
    
    period = []
    
    for line in lines:
        dtime = line[11:]
        ed_last = dtime.split(' ')
        ed = ed_last[0]
        last = float(ed_last[1][0:-1])
        sec = float(ed[0:2]) * 3600.0 + float(ed[3:5]) * 60.0 + float(ed[6:])
        
        period.append((sec-last+0.001, sec))
    
    period.sort(key=lambda t:t[0])
    
    pq = []
    
    for time in period:
        st = time[0]
        while(pq):
            if st - 1 > pq[0][1][1]:
                heapq.heappop(pq)
            else:
                break
                
        heapq.heappush(pq, (time[1], time))
        answer = max(answer, len(pq))
    
    return answer

t1 = ["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]
t2 = ["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"]
print(solution(t2))