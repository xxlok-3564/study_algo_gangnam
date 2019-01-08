CMD_LEN = int(input())
DEQUE = []
DEQUE_SIZE = len(DEQUE)

for cmd_idx in range(CMD_LEN):
    input_cmd = input()
    cmd = input_cmd.split(' ')[0]

    if (cmd == 'push_front'):
        DEQUE.insert(0, int(input_cmd.split(' ')[1]))
        DEQUE_SIZE += 1

    elif (cmd == 'push_back'):
        DEQUE.append(int(input_cmd.split(' ')[1]))
        DEQUE_SIZE += 1

    elif (cmd == 'pop_front'):
        if DEQUE_SIZE == 0:
            print(-1)
        else:
            print(DEQUE[0])
            DEQUE.pop(0)
            DEQUE_SIZE -= 1

    elif (cmd == 'pop_back'):
        if DEQUE_SIZE == 0:
            print(-1)
        else:
            print(DEQUE[-1])
            DEQUE.pop()
            DEQUE_SIZE -= 1

    elif (cmd == 'size'):
        print(DEQUE_SIZE)

    elif (cmd == 'empty'):
        if DEQUE_SIZE == 0:
            print(1)
        else:
            print(0)

    elif (cmd == 'front'):
        if DEQUE_SIZE == 0:
            print(-1)
        else:
            print(DEQUE[0])

    elif (cmd == 'back'):
        if DEQUE_SIZE == 0:
            print(-1)
        else:
            print(DEQUE[-1])