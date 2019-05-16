from collections import deque
import sys

input = sys.stdin.readline

stack = deque()


def NUM(x):  # X를 스택의 가장 위에 저장한다.
    stack.append(x)


def POP():  # 스택 가장 위의 숫자를 제거한다.
    if not stack:
        return True
    stack.pop()
    return False


def INV():  # 첫 번째 수의 부호를 바꾼다. (42 -> -42)
    if not stack:
        return True
    stack[-1] *= -1
    return False


def DUP():  # 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
    if not stack:
        return True
    stack.append(stack[-1])
    return False


def SWP():  # 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
    if len(stack) < 2:
        return True
    stack[-1], stack[-2] = stack[-2], stack[-1]
    return False


def ADD():  # 첫 번째 숫자와 두 번째 숫자를 더한다.
    if len(stack) < 2:
        return True

    result = stack.pop() + stack.pop()
    if abs(result) > 10 ** 9:
        return True
    stack.append(result)
    return False


def SUB():  # 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
    if len(stack) < 2:
        return True
    result = -stack.pop() + stack.pop()
    if abs(result) > 10 ** 9:
        return True
    stack.append(result)
    return False


def MUL():  # 첫 번째 숫자와 두 번째 숫자를 곱한다.
    if len(stack) < 2:
        return True
    result = stack.pop() * stack.pop()
    if abs(result) > 10 ** 9:
        return True
    stack.append(result)
    return False


# 나눗셈의 피연산자에 음수가 있을 때는, 그 수를 절댓값을 씌운 뒤 계산한다. 그리고 나서 몫과 나머지의 부호는 다음과 같이 결정한다.
# 피연산자중 음수가 한 개일때는 몫의 부호가 음수이다. 이 경우를 제외하면 몫의 부호는 항상 양수이다.
def DIV():  # 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
    if len(stack) < 2:
        return True

    t1, t2 = stack.pop(), stack.pop()
    if t1 == 0:
        return True

    if t1 * t2 < 0:
        result = -(abs(t2) // abs(t1))
    else:
        result = abs(t2) // abs(t1)
    stack.append(result)
    return False


# 나머지의 부호는 피제수의 부호와 같다.
def MOD():  # 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
    if len(stack) < 2:
        return True

    t1, t2 = stack.pop(), stack.pop()
    if t1 == 0:
        return True
    result = abs(t2) % abs(t1)
    if t2 < 0:
        result *= -1
    stack.append(result)
    return False


def run():  # 현재 프로그램을 수행. 스택에 남은 원소가 하나면 그 값 출력, 아니면 ERROR.
    error = False
    for command in programs:
        if command[0] == 'N':
            NUM(int(command.split()[1]))
        else:
            error = func_dict[command]()

        if error:
            return 'ERROR'

    if len(stack) != 1:
        return 'ERROR'
    else:
        return stack[0]


func_dict = {'NUM': NUM, 'POP': POP, 'INV': INV, 'DUP': DUP, 'SWP': SWP,
             'ADD': ADD, 'SUB': SUB, 'MUL': MUL, 'DIV': DIV, 'MOD': MOD}

# 마지막에 빈칸 출력을 안하기 위해서...길어지지만 이렇게..
programs = []
while 1:
    now = input().rstrip()
    if now == 'END':
        break
    elif now == 'QUIT':
        exit()
    else:
        programs.append(now)

for _ in range(int(input())):
    stack = deque()
    stack.append(int(input()))
    print(run())

# 빈칸 입력..
input()
while 1:
    programs = []
    while 1:
        now = input().rstrip()
        if now == 'END':
            break
        elif now == 'QUIT':
            exit()
        else:
            programs.append(now)

    print()

    for _ in range(int(input())):
        stack = deque()
        stack.append(int(input()))
        print(run())

    # 빈칸 입력..
    input()