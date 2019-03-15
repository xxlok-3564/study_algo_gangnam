N = int(input())

check = [0] * 10

if N == 0:
    check[0] += 1
else:
    while N:
        a = N % 10
        if a == 6 or a == 9:
            if check[6] == check[9]:
                check[6] += 1
            elif check[6] > check[9]:
                check[9] += 1
            elif check[6] < check[9]:
                check[6] += 1
        else:
            check[a] += 1

        N //= 10

print(max(check))
