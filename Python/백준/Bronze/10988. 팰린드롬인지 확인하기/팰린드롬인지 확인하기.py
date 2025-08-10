word = input().strip()

# 팰린드롬 확인: 문자열과 뒤집은 문자열이 같은지 비교
if word == word[::-1]:
    print(1)  # 팰린드롬이면 1
else:
    print(0)  # 팰린드롬이 아니면 0