# def solution(s):
#     answer = 1000000007
    
#     slen = len(s)
#     if slen == 1:
#         return 1
    
#     for i in range(1, slen//2 + 1):
#         tempres = ""
        
#         prefix = s[0:i]
#         cnt = 1
#         idx = i
        
#         while(True):
#             now = s[idx:idx+i]
#             print("now : ", now)
#             if now == prefix:
#                 cnt+=1
#             else:
#                 if cnt == 1:
#                     tempres += prefix
#                 else:
#                     tempres += (str(cnt) + prefix)
#                 prefix = now
#                 cnt = 1
#             idx+=i
            
#             if idx >= slen:
#                 if cnt == 1:
#                     tempres += s[idx-i:]
#                 else:
#                     tempres += (str(cnt) + s[idx-i:])
#                 break
#         print(tempres)
#         answer = min(answer, len(tempres))
        
#     return answer
        

# s = input()
# a = solution(s)
# print(a)



## BEST SOLUTION
def compress(text, tok_len):
    words = [text[i:i+tok_len] for i in range(0, len(text), tok_len)]
    res = []
    cur_word = words[0]
    cur_cnt = 1
    
    for a, b in zip(words, words[1:] + ['']):
        if a == b:
            cur_cnt += 1
        else:
            res.append([cur_word, cur_cnt])
            cur_word = b
            cur_cnt = 1
    ret = sum(len(word) + (len(str(cnt)) if cnt > 1 else 0) for word, cnt in res)
    return ret

def solution(text):
    return min(compress(text, tok_len) for tok_len in list(range(1, int(len(text)/2) + 1)) + [len(text)])

a = [
    "aabbaccc",
    "ababcdcdababcdcd",
    "abcabcdede",
    "abcabcabcabcdededededede",
    "xababcdcdababcdcd",

    'aaaaaa',
]

for x in a:
    print(solution(x))
