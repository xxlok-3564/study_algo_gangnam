N = int(input())

for tc in range(N):

    three = list(map(int, input().split()))

    three = sorted(three)

    print("Scenario #%d:" %(tc + 1))

    if three[0]**2 + three[1]**2 == three[2]**2:
        print("yes")
    else:
        print("no")
    print()
