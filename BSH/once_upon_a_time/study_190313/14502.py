from collections import deque

N, M = map(int, input().split())

board = []
init_virus = []
ans = 0

for y in range(N):
    board.append(list(map(int, input().split())))
    for x in range(M):
        if board[y][x] == 2:
            init_virus.append([x, y])


def get_next_wall(pos):
    x, y = pos

    x += 1
    if x >= M:
        x = 0
        y += 1

    while 1:
        if y == N:
            return 0
        if board[y][x] != 0:
            x += 1
            if x >= M:
                x = 0
                y += 1
        else:
            return [x, y]


dx = (0, 0, -1, 1)
dy = (-1, 1, 0, 0)


def set_wall(pos, wall_num):
    global ans
    if wall_num == 3:
        visit = [[0] * M for _ in range(N)]
        bfs_q = deque()
        for virus_pos in init_virus:
            bfs_q.append(virus_pos)
            visit[virus_pos[1]][virus_pos[0]] = 1

        while bfs_q:
            current = bfs_q.popleft()
            for df in range(4):
                new = [current[0] + dx[df], current[1] + dy[df]]
                if 0 <= new[0] < M and 0 <= new[1] < N and (board[new[1]][new[0]] == 0) and not visit[new[1]][new[0]]:
                    visit[new[1]][new[0]] = 1
                    bfs_q.append(new)

        partial_ans = 0
        for y in range(N):
            for x in range(M):
                if visit[y][x] == 0 and board[y][x] == 0:
                    partial_ans += 1

        if ans < partial_ans:
            ans = partial_ans

        return
    else:
        next_wall = get_next_wall(pos)
        while 1:
            if next_wall == 0:
                return
            board[next_wall[1]][next_wall[0]] = 1
            set_wall(next_wall, wall_num + 1)
            board[next_wall[1]][next_wall[0]] = 0
            next_wall = get_next_wall(next_wall)


set_wall([-1, 0], 0)

print(ans)
