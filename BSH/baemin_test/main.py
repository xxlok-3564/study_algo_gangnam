# def solution(money):
#     answer = []
#
#     money_pack = [50000, 10000, 5000, 1000, 500, 100, 50, 10, 1]
#
#
#
#     for idx in range(len(money_pack)):
#         answer.append(money // money_pack[idx])
#         money = money - (money // money_pack[idx])
#
#     return answer


# def solution(pobi, crong):
#     answer = 0
#
#     if not (pobi[0] % 2 == 1 and pobi[0] + 1 == pobi[1]):
#         return -1
#
#     if not (crong[0] % 2 == 1 and crong[0] + 1 == crong[1]):
#         return -1
#
#     pobi_max = 0
#     crong_max = 0
#
#     for idx in range(2):
#         p = pobi[idx]
#         c = crong[idx]
#
#         sum_p = 0
#         while p:
#             sum_p += (p % 10)
#             p //= 10
#
#         if sum_p > pobi_max:
#             pobi_max = sum_p
#
#         sum_c = 0
#         while c:
#             sum_c += (c % 10)
#             c //= 10
#
#         if sum_c > crong_max:
#             crong_max = sum_c
#
#         p = pobi[idx]
#         c = crong[idx]
#
#         mul_p = 1
#         while p:
#             mul_p *= (p % 10)
#             p //= 10
#         if mul_p > pobi_max:
#             pobi_max = mul_p
#
#         mul_c = 1
#         while c:
#             mul_c *= (c % 10)
#             c //= 10
#
#         if mul_c > crong_max:
#             crong_max = mul_p
#
#     if crong_max > pobi_max:
#         answer = 2
#     elif crong_max == pobi_max:
#         answer = 0
#     elif crong_max < pobi_max:
#         answer = 1
#
#     return answer

# def solution(lands, wells, point):
#     answer = True
#
#     for land_loc in lands:
#         if (land_loc[2] <= point[0] or point[2] <= land_loc[0]) and( land_loc[3] <= point[1] or point[3] <= land_loc[1]):
#             return False
#
#     for well_loc in wells:
#         if not (point[0] <= well_loc[0] and well_loc[2] <= point[2] and point[1] <= well_loc[1] and well_loc[3] <=
#                 point[3]):
#             return False
#
#     return answer

def time_to_sec(t):
    sec = t[2]
    sec += t[1] * 60
    sec += (t[0] - 9) * 3600
    return sec


def solution(totalTicket, logs):
    answer = []

    before = 0
    current_user = ""

    list_log = []

    for log in logs:
        split_log = log.split(" ")
        split_log[2] = time_to_sec(list(map(int, split_log[2].split(":"))))
        list_log.append(split_log)

    list_log = sorted(list_log, key=lambda x: x[2])

    for log in list_log:

        if log[1] == 'request':
            if log[2] - before >= 0 and 3600 - log[2] >= 60:
                if totalTicket > 0:
                    if not log[0] in answer:
                        before = log[2] + 60
                        totalTicket -= 1
                        current_user = log[0]
                        answer.append(log[0])


        elif log[1] == 'leave' and log[0] == current_user:
            if log[0] in answer:
                answer.remove(log[0])
                current_user = ""
                before = 0

    answer = sorted(answer)

    return answer


totalTicket = 2000
logs = [
    "pich request 09:00:00",
    "brown request 09:23:11",
    "woni request 09:12:29",
    "brown leave 09:23:44",
    "jason request 09:33:51",
    "jun request 09:33:56",
    "cu request 09:34:02"
]

print(solution(totalTicket, logs))

print(solution(300, ["brown request 9:59:01"]))


if pobi[0]%2==0 or pobi[1]%2 or crong[0]%2==0 or crong[1]%2:
        return -1