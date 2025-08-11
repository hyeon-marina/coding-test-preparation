word = input().upper()
frequency = [0] * 26

for char in word:
    frequency[ord(char) - ord('A')] += 1

max_freq = max(frequency)
if frequency.count(max_freq) > 1:
    print("?")
else:
    print(chr(frequency.index(max_freq) + ord('A')))
