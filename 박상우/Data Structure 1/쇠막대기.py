pattern = input()
# ()(((()())(())()))(()) 이런식.
# 레이저를 제외하고 위에 있는 놈들부터 없애면서 개수를 추가하자.
# 왼쪽괄호가 나오면 tot에 추가, 안닫힌 개수 저장, 레이저가 나오면 그 개수만큼 추가됨.
left = tot = 0
LASER = False
for i in range(len(pattern)):
    if LASER:
        LASER = False
        continue
    else:
        if pattern[i] == '(':
            if pattern[i+1] == ')':  # LASER이면
                tot += left
                LASER = True
                continue
            left += 1
            tot += 1
        if pattern[i] == ')':  # 닫히면,
            left -= 1
print(tot)
