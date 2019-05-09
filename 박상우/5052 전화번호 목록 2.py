import sys
input = sys.stdin.readline

NUMS = 10

class NumTrie():
    consistency = True
    def __init__(self):
        self.terminal = False
        self.children = [None] * NUMS

    # 포인터가 없기 때문에 현재 key의 몇번째 원소를 보고 있는지 알려주는 index i가 추가로 필요.
    def insert(self, key, i=0):
        if i == len(key):
            self.terminal = True
            if any(self.children[i] for i in range(10)):
                NumTrie.consistency = False
        else:
            next_ = int(key[i])
            if self.children[next_] == None:
                self.children[next_] = NumTrie()
            self.children[next_].insert(key, i + 1)
            if self.terminal:
                NumTrie.consistency = False

if __name__ == "__main__":
    for _ in range(int(input())):
        consistency = True
        root = NumTrie()
        for _ in range(int(input())):
            if not NumTrie.consistency:
                input()
            else:
                root.insert(input().rstrip())

        if NumTrie.consistency:
            print('YES')
        else:
            print('NO')
            NumTrie.consistency = True