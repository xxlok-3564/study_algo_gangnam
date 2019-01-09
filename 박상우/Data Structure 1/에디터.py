import sys
from collections import deque
left = deque(sys.stdin.readline().strip())
right = deque()
N = int(sys.stdin.readline())
for _ in range(N):
    command = sys.stdin.readline()
    if command[0] == 'L':
        try:
            right.append(left.pop())
        except:
            continue
    elif command[0] == 'D':
        try:
            left.append(right.pop())
        except:
            continue
    elif command[0] == 'B':
        try:
            left.pop()
        except:
            continue
    elif command[0] == 'P':
        left.append(command[2])

right.reverse()
print(''.join(left + right))
