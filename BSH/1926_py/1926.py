from collections import deque

N, M = map(int, input().split())

board = []
visit = [[0] * M for _ in range(N)]

for y in range(N):
    board.append(list(map(int, input().split())))

picture_max = 0
num_picture = 0

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

for y in range(N):
    for x in range(M):
        if board[y][x] == 1 and visit[y][x] == 0:
            num_picture += 1

            picture_size = 1
            bfs_q = deque()
            visit[y][x] = 1
            bfs_q.append([x, y])

            while bfs_q:
                current = bfs_q.popleft()

                for diff in range(4):
                    new = [current[0] + dx[diff], current[1] + dy[diff]]
                    if 0 <= new[0] < M and 0 <= new[1] < N and visit[new[1]][new[0]] == 0 and board[new[1]][
                        new[0]] == 1:
                        bfs_q.append(new)
                        visit[new[1]][new[0]] += 1
                        picture_size += 1

            if picture_size > picture_max: picture_max = picture_size

print(num_picture)
print(picture_max)
