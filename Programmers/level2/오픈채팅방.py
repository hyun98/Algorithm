ENTER = "Enter"
LEAVE = "Leave"

D = {
    "Enter": "님이 들어왔습니다.",
    "Leave": "님이 나갔습니다."
}

def solution(record):
    answer = []
    data = {}
    new_record = []
    
    for rec in record:
        rec = rec.split(' ')
        if rec[0] == ENTER or rec[0] == "Change":
            data[rec[1]] = rec[2]
        
        new_record.append([rec[0], rec[1]])
    
    for nr in new_record:
        if nr[0] == ENTER:
            answer.append(data[nr[1]] + D[ENTER])
        elif nr[0] == LEAVE:
            answer.append(data[nr[1]] + D[LEAVE])
    
    return answer

r = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
a = solution(r)
print(a)