CMD_LEN = int(input())
QUEUE = []
QUEUE_SIZE = len(QUEUE)

for cmd_idx in range(CMD_LEN):
    input_cmd = input()
    cmd = input_cmd.split(' ')[0]

    if(cmd == 'push'):
        QUEUE.append(int(input_cmd.split(' ')[1]))
        QUEUE_SIZE += 1

    elif (cmd == 'pop'):
        if QUEUE_SIZE == 0:
            print(-1)
        else:
            print(QUEUE[0])
            QUEUE.pop(0)
            QUEUE_SIZE -= 1

    elif (cmd == 'size'):
        print(QUEUE_SIZE)

    elif (cmd == 'empty'):
        if QUEUE_SIZE == 0:
            print(1)
        else:
            print(0)

    elif(cmd == 'front'):
        if QUEUE_SIZE == 0:
            print(-1)
        else:
            print(QUEUE[0])

    elif(cmd == 'back'):
        if QUEUE_SIZE == 0:
            print(-1)
        else:
            print(QUEUE[-1])