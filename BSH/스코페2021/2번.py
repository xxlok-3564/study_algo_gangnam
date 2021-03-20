import sys


def main():
    length_of_board = int(sys.stdin.readline().rstrip())
    board = str(sys.stdin.readline().rstrip())

    memo = [0 for _ in range(length_of_board + 1)]

    memo[0] = 1 if board[0] == "1" else 0
    memo[1] = 1 if board[1] == "1" else 0

    for idx, char in enumerate(board):
        if idx == 0 or idx == 1:
            continue

        if char == "0":
            continue

        memo[idx] = memo[idx - 1] + memo[idx - 2]

    print(memo[length_of_board - 1])


if __name__ == '__main__':
    main()
