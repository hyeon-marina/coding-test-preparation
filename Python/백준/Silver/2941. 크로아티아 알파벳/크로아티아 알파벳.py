sentence = input()
croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for cro in croatia:
    sentence = sentence.replace(cro, '*')  # 크로아티아 알파벳 부분을 '*'로 대체

print(len(sentence))
