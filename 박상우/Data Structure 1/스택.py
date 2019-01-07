N=int(input())
lst=[]
def push(X):
    lst.append(X)

def pop():
    return lst.pop(-1) if len(lst)!=0 else -1

def size():
    return len(lst)

def empty():
    if len(lst)==0:
        return 1
    else:
        return 0

def top():
    return lst[-1] if len(lst)!=0 else -1

for i in range(N):
    command=input()
    if command[:4]=='push':
        push(int(command[5:]))
    elif command=='pop':
        print(pop())
    elif command=='size':
        print(size())
    elif command=='empty':
        print(empty())
    elif command=='top':
        print(top())
