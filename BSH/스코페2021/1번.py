import sys


class myTime(object):

    def __init__(self, raw_value):
        self.raw_value = raw_value
        self.h = int(raw_value[0:2])
        self.m = int(raw_value[3:5])

    def __lt__(self, other):
        if self.h == other.h:
            return self.m < other.m

        return self.h < other.h

    def __le__(self, other):
        if self.h == other.h:
            return self.m <= other.m

        return self.h <= other.h


def parse_line(value):
    # print(value)
    return myTime(value[0:5]), myTime(value[8:13])


def can_meet(current_left, current_right, whole_left, whole_right):
    return current_left <= whole_right or whole_left <= current_right


def renew_whole_time(current_left, current_right, whole_left, whole_right):
    new_left = current_left if whole_left < current_left else whole_left
    new_right = current_right if current_right < whole_right else whole_right

    if not new_left < new_right:
        print("-1")
        exit(0)

    return new_left, new_right


def main():
    number_of_user = int(sys.stdin.readline().rstrip())
    # print(number_of_user)

    initial_raw_input = str(sys.stdin.readline().rstrip())
    whole_left_time, whole_right_time = parse_line(initial_raw_input)

    for _ in range(number_of_user - 1):
        raw_input = str(sys.stdin.readline().rstrip())
        current_left, current_right = parse_line(raw_input)

        if not can_meet(current_left, current_right, whole_left_time, whole_right_time):
            print("-1")
            exit(0)

        whole_left_time, whole_right_time = renew_whole_time(current_left,
                                                             current_right,
                                                             whole_left_time,
                                                             whole_right_time)

    print(whole_left_time.raw_value
          + " ~ "
          + whole_right_time.raw_value)


if __name__ == "__main__":
    main()
