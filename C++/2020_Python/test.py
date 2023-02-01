def solution(participant, completion):
    for i in participant:
        if i not in completion:
            answer = ''
    return answer

participant=['leo','kiki','eden']
completion=["kiki","eden"]
answer=solution(participant,completion)
answer