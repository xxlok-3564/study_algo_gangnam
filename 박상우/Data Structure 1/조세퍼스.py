from collections import deque

N, M = map(int, input().split())

c_q = deque(range(1, N+1))

idx = M - 1
answer = []
while c_q:
    # print('idx', idx)
    answer.append(str(c_q[idx]))
    del c_q[idx]
    N -= 1
    if N == 0:
        break
    idx += (M % N) - 1
    idx = idx % N

print('<{}>'.format(', '.join(answer)))
