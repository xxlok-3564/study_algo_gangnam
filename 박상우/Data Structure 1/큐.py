N = int(input())
queue = []

def push(x):    # 정수를 큐에 넣음
    queue.append(x)

def pop():      # 가장 앞에 있는 수를 빼고 출력. 수가 없으면 -1 출력
    if len(queue) == 0:
        print(-1)
    else:
        print(queue.pop(0))

def size():     # 들어있는 정수의 갯수 출력
    print(len(queue))

def empty():    # 비어있으면 1, 아니면 0 출력
    print(int(not bool(len(queue))))

def front():    # 큐 가장 앞에있는 수를 출력
    if len(queue) == 0:
        print(-1)
    else:
        print(queue[0])

def back():     # 큐 가장 뒤에 있는 수를 출력
    if len(queue) == 0:
        print(-1)
    else:
        print(queue[-1])

func_lst = [pop,size,empty,front,back]
func_str = ['pop','size','empty','front','back']
for i in range(N):
    f = input().split(' ')
    if len(f) == 2:
        push(int(f[1]))
    else:
        func_lst[func_str.index(f[0])]()
