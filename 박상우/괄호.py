T = int(input())

for t in range(T):
    left = 0
    ps = input()
    for letter in ps:
        if letter == '(':
            left += 1
        elif letter == ')':
            left -= 1
            if left < 0:
                print('NO')
                break
        else:
            print('NO')
            break
    if left < 0:
        continue
    elif left == 0:
        print('YES')
    else:
        print('NO')
