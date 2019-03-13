def solution(m, n, board):
    answer = 0

    mutable_board = []

    for line in board:
        mutable_board.append(list(map(ord, line)))

    while 1:
        score = False
        check = [[False] * n for _ in range(m)]

        for x in range(n - 1):
            for y in range(m - 1):
                if mutable_board[y][x] == mutable_board[y][x + 1] == mutable_board[y + 1][x] == mutable_board[y + 1][
                    x + 1] and mutable_board[y][x] != 0:
                    check[y][x] = check[y + 1][x + 1] = check[y][x + 1] = check[y + 1][x] = True
                    score = True

        for x in range(n):
            for y in range(m):
                if check[y][x] == True:
                    mutable_board[y][x] = 0
                    answer += 1

        if score == False:
            break

        for x in range(n):
            for y in reversed(range(m)):
                if mutable_board[y][x] == 0:
                    for cy in reversed(range(y - 1)):
                        if mutable_board[cy][x] != 0:
                            mutable_board[y][x] = mutable_board[cy][x]
                            mutable_board[cy][x] = 0
                            break

    return answer


print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
