from collections import deque

row = 12
col = 6

mutable_board = [list(map(ord, input())) for _ in range(12)]

dot = ord('.')

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

ans = 0

while 1:

    score = False
    visit = [[False] * 6 for _ in range(12)]
    for y in range(row):
        for x in range(col):
            if mutable_board[y][x] != dot and visit[y][x] == False:
                bfs_q = deque()
                visit_log = []
                init_color = mutable_board[y][x]

                bfs_q.append([x, y])
                visit_log.append([x, y])
                visit[y][x] = True
                while bfs_q:
                    current = bfs_q.popleft()

                    for diff in range(4):
                        new = [current[0] + dx[diff], current[1] + dy[diff]]
                        if 0 <= new[0] < col and 0 <= new[1] < row and visit[new[1]][new[0]] is False and \
                                mutable_board[new[1]][new[0]] == init_color:
                            visit[new[1]][new[0]] = True
                            bfs_q.append(new)
                            visit_log.append(new)

                if len(visit_log) >= 4:
                    score = True
                    for pos in visit_log:
                        mutable_board[pos[1]][pos[0]] = dot

    if score:
        ans += 1
    else:
        break

    for x in range(col):
        for y in reversed(range(row)):
            if mutable_board[y][x] == dot:
                for cy in reversed(range(y)):
                    if mutable_board[cy][x] != dot:
                        mutable_board[y][x] = mutable_board[cy][x]
                        mutable_board[cy][x] = dot
                        break

print(ans)
