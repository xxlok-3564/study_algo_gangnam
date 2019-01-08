tmp_input = input()
N = int(tmp_input.split(' ')[0])
M = int(tmp_input.split(' ')[1])

QUEUE = []
for i in range(N):
    QUEUE.append(i+1)
print(QUEUE)
print("<", end='')
for i in range(N-1):
    for j in range(M-1):
        QUEUE.append(QUEUE[0])
        QUEUE.pop(0)
    print(str(QUEUE[0]) + ', ', end='')
    QUEUE.pop(0)
print(str(QUEUE[0]) + '>', end='')