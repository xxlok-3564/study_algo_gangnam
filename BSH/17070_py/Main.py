N = int(input())
board = []

dp_memo = [[[-1] * 3 for _ in range(N)] for _ in range(N)]

for y in range(N):
    board.append(list(map(int, input().split())))

dp_memo[0][1][0] = 1


def get_cost(board, dp_memo, x, y, type):
    if 0 <= x < N and 0 <= y < N:
        if dp_memo[y][x][type] != -1:
            return dp_memo[y][x][type]

        if type == 0:
            if board[y][x] == 1:
                dp_memo[y][x][type] = 0
            else:
                dp_memo[y][x][type] = get_cost(board, dp_memo, x - 1, y, 0) + get_cost(board, dp_memo, x - 1, y, 2)
        elif type == 1:
            if board[y][x] == 1:
                dp_memo[y][x][type] = 0
            else:
                dp_memo[y][x][type] = get_cost(board, dp_memo, x, y - 1, 1) + get_cost(board, dp_memo, x, y - 1, 2)

        elif type == 2:
            if board[y][x] == 1 or board[y - 1][x] == 1 or board[y][x - 1] == 1:
                dp_memo[y][x][type] = 0
            else:
                dp_memo[y][x][type] = get_cost(board, dp_memo, x - 1, y - 1, 0) \
                                      + get_cost(board, dp_memo, x - 1, y - 1, 1) \
                                      + get_cost(board, dp_memo, x - 1, y - 1, 2)

        return dp_memo[y][x][type]

    else:
        return 0


print(get_cost(board, dp_memo, N - 1, N - 1, 0) + get_cost(board, dp_memo, N - 1, N - 1, 1) + get_cost(board, dp_memo,
                                                                                                       N - 1, N - 1, 2))
