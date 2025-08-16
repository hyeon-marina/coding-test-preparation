def solution(record):
    uid2name = {}
    # 1차 순회: uid의 최신 닉네임 저장
    for entry in record:
        parts = entry.split()
        cmd = parts[0]
        uid = parts[1]
        if cmd in ('Enter', 'Change'):
            name = parts[2]
            uid2name[uid] = name

    answer = []
    # 2차 순회: Enter / Leave 기록에 대해 메시지 생성
    for entry in record:
        parts = entry.split()
        cmd = parts[0]
        uid = parts[1]
        current_name = uid2name[uid]
        if cmd == 'Enter':
            answer.append(f"{current_name}님이 들어왔습니다.")
        elif cmd == 'Leave':
            answer.append(f"{current_name}님이 나갔습니다.")

    return answer