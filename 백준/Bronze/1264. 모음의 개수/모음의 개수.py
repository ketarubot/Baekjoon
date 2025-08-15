vowels = ['a', 'e', 'i', 'o', 'u'] + ['A', 'E', 'I', 'O', 'U']

while True:
    sentence = input()
    if sentence == '#': break
    count = 0
    for vowel in vowels:
        count += sentence.count(vowel)
    print(count)