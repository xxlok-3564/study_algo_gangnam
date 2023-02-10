# https://programmers.co.kr/learn/courses/30/lessons/12927?language=python3
"""
회사원 Demi는 가끔은 야근을 하는데요, 야근을 하면 야근 피로도가 쌓입니다. 야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값입니다. Demi는 N시간 동안 야근 피로도를 최소화하도록 일할 겁니다.Demi가 1시간 동안 작업량 1만큼을 처리할 수 있다고 할 때, 퇴근까지 남은 N 시간과 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 함수 solution을 완성해주세요.

제한 사항
works는 길이 1 이상, 20,000 이하인 배열입니다.
works의 원소는 50000 이하인 자연수입니다.
n은 1,000,000 이하인 자연수입니다.
"""


def solution(n, works):
    answer = 0
    # 가장 남은 일의 값이 큰 것을 줄이는 것이 효율적
    max_work_value = -1
    works_dict = dict()

    # works_dict에 value->갯수 형태로 변경
    for work_value in works:
        if work_value > max_work_value:
            max_work_value = work_value

        if work_value in works_dict:
            works_dict[work_value] += 1
        else:
            works_dict[work_value] = 1

    for remain_step in range(n):

        works_dict[max_work_value] -= 1

        if max_work_value - 1 in works_dict:
            works_dict[max_work_value - 1] += 1
        else:
            works_dict[max_work_value - 1] = 1

        # max_work_value 갱신
        if works_dict[max_work_value] == 0:
            max_work_value -= 1

        if max_work_value == 0:
            break

    for value in works_dict:
        answer += (value ** 2) * works_dict[value]

    return answer


def main():
    works = [4, 3, 3]
    n = 4

    print(solution(n, works))

    works = [2, 1, 2]
    n = 1

    print(solution(1, works))


if __name__ == "__main__":
    main()
