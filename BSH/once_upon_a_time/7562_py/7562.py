from collections import deque

T = int(input())

dx = (-1, 1, 2, 2, 1, -1, -2, -2)
dy = (-2, -2, -1, 1, 2, 2, 1, -1)

for _ in range(T):
    N = int(input())

    start = list(map(int, input().split()))
    end = list(map(int, input().split()))

    visit = [[-1] * N for __ in range(N)]
    bfs_q = deque()
    bfs_q.append(start)
    visit[start[1]][start[0]] = 0

    while bfs_q:
        current = bfs_q.popleft()
        if current == end:
            break
        for diff in range(8):
            new = [current[0] + dx[diff], current[1] + dy[diff]]
            if 0 <= new[0] < N and 0 <= new[1] < N and visit[new[1]][new[0]] == -1:
                visit[new[1]][new[0]] = visit[current[1]][current[0]] + 1
                bfs_q.append(new)

    print(visit[current[1]][current[0]])
