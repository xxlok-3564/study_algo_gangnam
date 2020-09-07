"""
문제
평면 상에 N개의 점이 찍혀있고, 그 점을 집합 P라고 하자. 집합 P의 벡터 매칭은 벡터의 집합인데, 모든 벡터는 집합 P의 한 점에서 시작해서, 또 다른 점에서 끝나는 벡터의 집합이다. 또, P에 속하는 모든 점은 한 번씩 쓰여야 한다.

V에 있는 벡터의 개수는 P에 있는 점의 절반이다.

평면 상의 점이 주어졌을 때, 집합 P의 벡터 매칭에 있는 벡터의 합의 길이의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.

테스트 케이스의 첫째 줄에 점의 개수 N이 주어진다. N은 짝수이다. 둘째 줄부터 N개의 줄에 점의 좌표가 주어진다. N은 20보다 작거나 같은 자연수이고, 좌표는 절댓값이 100,000보다 작거나 같은 정수다. 모든 점은 서로 다르다.

출력
각 테스트 케이스마다 정답을 출력한다. 절대/상대 오차는 10-6까지 허용한다.
"""
from itertools import combinations
from math import sqrt


def calc_distance(a, b):
    x = b[0] - a[0]
    y = b[1] - a[1]

    return sqrt(x ** 2 + y ** 2)


def all_selected(selected_dot):
    for selected in selected_dot:
        if not selected:
            return False
    return True


def dfs(dot_list, idx_list, selected_dot, total_distance):
    if all_selected(selected_dot):
        return total_distance

    remained = list()
    for idx in idx_list:
        if not selected_dot[idx]:
            remained.append(idx)

    candidates = combinations(remained, 2)

    for selected_two in candidates:
        selected_dot[selected_two[0]] = True
        selected_dot[selected_two[1]] = True

        vector_distance = calc_distance(dot_list[selected_two[0]], dot_list[selected_two[1]])
        total_distance += vector_distance

        result = dfs(dot_list, idx_list, selected_dot, total_distance)

        if result < total_distance:
            total_distance = result

        total_distance -= vector_distance

        selected_dot[selected_two[0]] = False
        selected_dot[selected_two[1]] = False

    return total_distance


def main():
    T = int(input())

    for _ in range(T):
        distance = 10000000000000000000000000000000.0
        num_dot = int(input())
        dot_list = []
        selected_dot = [False] * num_dot
        idx_list = [element for element in range(num_dot)]

        for _ in range(num_dot):
            x, y = map(int, input().split())
            dot_list.append([x, y])

        candidates = combinations(idx_list, 2)

        for selected_two in candidates:
            selected_dot[selected_two[0]] = True
            selected_dot[selected_two[1]] = True

            total_distance = calc_distance(dot_list[selected_two[0]], dot_list[selected_two[1]])

            result = dfs(dot_list, idx_list, selected_dot, total_distance)

            if result < distance:
                distance = result

            selected_dot[selected_two[0]] = False
            selected_dot[selected_two[1]] = False

        print(distance)


if __name__ == "__main__":
    main()
