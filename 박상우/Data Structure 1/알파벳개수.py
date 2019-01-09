S = input()
alphabet = 'abcdefghijklmnopqrstuvwxyz'
dict = {i: 0 for i in alphabet}

for l in S:
    dict[l] += 1

print(' '.join([str(dict[i]) for i in alphabet]))
