S = input()
alphabet = 'abcdefghijklmnopqrstuvwxyz'
alpha_dict = {i:-1 for i in alphabet}

for i in range(len(S)):
    if alpha_dict[S[i]] == -1:
        alpha_dict[S[i]] = i

print(' '.join([str(alpha_dict[i]) for i in alphabet]))
