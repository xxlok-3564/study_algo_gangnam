S = input()
alphabet = 'abcdefghijklmnopqrstuvwxyz'
alpha_dict = {i: 0 for i in alphabet}

for l in S:
    alpha_dict[l] += 1

print(' '.join([str(alpha_dict[i]) for i in alphabet]))
