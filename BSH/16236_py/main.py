from collections import deque

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

N = int(input())
board = []
fish_size = 2
ate = 0
total_time = 0

for y in range(N):
    board.append(list(map(int, input().split())))
    for x in range(N):
        if board[y][x] == 9:
            init_pos = [x, y]
            board[y][x] = 0


def get_next_pos(init_pos):
    global fish_size
    global total_time
    visit = [[0] * N for _ in range(N)]
    BFS_Q = deque()
    can_eat = []
    visit[init_pos[1]][init_pos[0]] = 1
    BFS_Q.append([init_pos, 0])

    while BFS_Q:
        current_pos, time = BFS_Q.popleft()
        for d in range(4):
            new_x, new_y = current_pos[0] + dx[d], current_pos[1] + dy[d]
            if 0 <= new_x < N and 0 <= new_y < N and board[new_y][new_x] <= fish_size and not visit[new_y][new_x]:
                visit[new_y][new_x] = 1
                BFS_Q.append([[new_x, new_y], time + 1])
                if 0 < board[new_y][new_x] < fish_size:
                    can_eat.append([[new_x, new_y], time + 1])

    if len(can_eat) == 0:
        return 0
    else:
        next_pos = sorted(can_eat, key=lambda element: (element[1], element[0][1], element[0][0]))[0]
        board[next_pos[0][1]][next_pos[0][0]] = 0
        total_time += next_pos[1]
        return next_pos[0]


def eat():
    global ate
    global fish_size
    ate += 1
    if ate == fish_size:
        ate = 0
        fish_size += 1


next_pos = get_next_pos(init_pos)

while 1:

    if next_pos == 0:
        break
    else:
        eat()
        next_pos = get_next_pos(next_pos)

print(total_time)