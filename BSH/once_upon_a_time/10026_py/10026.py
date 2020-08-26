from collections import deque

N = int(input())

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

normal = 0
board = [list(input()) for _ in range(N)]
visit = [[False] * N for _ in range(N)]
for y in range(N):
    for x in range(N):
        if visit[y][x] is False:
            normal += 1
            init_color = board[y][x]
            bfs_q = deque()
            bfs_q.append([x, y])
            while bfs_q:
                current = bfs_q.popleft()
                for diff in range(4):
                    new = [current[0] + dx[diff], current[1] + dy[diff]]
                    if 0 <= new[0] < N and 0 <= new[1] < N and visit[new[1]][new[0]] is False and board[new[1]][
                        new[0]] == init_color:
                        visit[new[1]][new[0]] = True
                        bfs_q.append(new)


def change(a):
    if a == 'R':
        return 'G'
    else:
        return a


blind = 0
board = [list(map(change, board[i])) for i in range(N)]
visit = [[False] * N for _ in range(N)]
for y in range(N):
    for x in range(N):
        if visit[y][x] is False:
            blind += 1
            init_color = board[y][x]
            bfs_q = deque()
            bfs_q.append([x, y])
            while bfs_q:
                current = bfs_q.popleft()
                for diff in range(4):
                    new = [current[0] + dx[diff], current[1] + dy[diff]]
                    if 0 <= new[0] < N and 0 <= new[1] < N and visit[new[1]][new[0]] is False and board[new[1]][
                        new[0]] == init_color:
                        visit[new[1]][new[0]] = True
                        bfs_q.append(new)

print(normal, blind)
