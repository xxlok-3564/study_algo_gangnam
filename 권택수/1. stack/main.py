CMD_LEN = int(input())
STACK = []
STACK_SIZE = len(STACK)

for cmd_idx in range(CMD_LEN):
    input_cmd = input()
    cmd = input_cmd.split(' ')[0]

    if(cmd == 'push'):
        STACK.append(int(input_cmd.split(' ')[1]))
        STACK_SIZE += 1

    elif(cmd == 'top'):
        if STACK_SIZE == 0:
            print(-1)
        else:
            print(STACK[-1])

    elif(cmd == 'size'):
        # size()
        print(STACK_SIZE)

    elif(cmd == 'pop'):
        if STACK_SIZE == 0:
            print(-1)
        else:
            print(STACK[-1])
            STACK.pop()
            STACK_SIZE -= 1

    elif(cmd == 'empty'):
        if STACK_SIZE == 0:
            print(1)
        else:
            print(0)
