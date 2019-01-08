CMD_LEN = int(input())

for i in range(CMD_LEN):
    VPS = list(input())
    while VPS != []:
        if VPS[0] == ')':
            print('NO')
            break
        else:
            if ')' in VPS:
                VPS.remove(')')
                VPS.remove('(')
            else:
                print("NO")
                break
    if VPS != []:
        print("YES")