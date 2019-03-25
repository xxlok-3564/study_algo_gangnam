N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]

location = dict()

pos = 0
for y in range(N):
    for x in range(N):
        location[board[y][x]] = [pos % N, pos // N]


def get_bishop_cost(before, after):
    if ((before[0] + before[1]) % 2) != ((after[0] + after[1]) % 2):
        return -1

    bishop_dx = (-1, 1, 1, -1)
    bishop_dy = (-1, -1, 1, 1)

    new = [before for _ in range(4)]
    new
