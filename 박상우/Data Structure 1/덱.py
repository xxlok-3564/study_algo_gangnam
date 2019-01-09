N = int(input())
Deque = []

def push_front(X): # 정수 X를 덱의 앞에 넣는다.
    Deque.insert(0,X)

def push_back(X):  # 정수 X를 덱의 뒤에 넣는다.
    Deque.append(X)

def pop_front():   # 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if len(Deque) == 0:
        print(-1)
    else:
        print(Deque.pop(0))

def pop_back():    # 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if len(Deque) == 0:
        print(-1)
    else:
        print(Deque.pop())

def size():        # 덱에 들어있는 정수의 개수를 출력한다.
    print(len(Deque))

def empty():       # 덱이 비어있으면 1을, 아니면 0을 출력한다.
    print(int(not bool(len(Deque))))

def front():       # 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if len(Deque) == 0:
        print(-1)
    else:
        print(Deque[0])

def back():        # 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if len(Deque) == 0:
        print(-1)
    else:
        print(Deque[-1])

func_lst = [push_front, push_back, pop_front, pop_back, size, empty, front, back]
func_str = ['push_front', 'push_back', 'pop_front', 'pop_back','size','empty','front','back']
for i in range(N):
    f = input().split(' ')
    if len(f) == 2:
        func_lst[func_str.index(f[0])](f[1])
    else:
        func_lst[func_str.index(f[0])]()
