# 개선 필요사항
# 공간복잡도, 시간

class Node:

    def __init__(self):
        self.next_node = {}
        self.fin = False
        self.depth = None

    def mark(self, word, depth):
        self.depth = depth

        if len(word) == 0:
            self.fin = True
            return

        if word[0] not in self.next_node:
            self.next_node[word[0]] = Node()

        self.depth = depth
        self.next_node[word[0]].mark(word[1:], depth + 1)

    def below_sum(self, origin_word, word):

        if word == "":
            if self.fin:
                return 1
            else:
                return 0

        if word[0] == "?":
            result = 0

            for node in self.next_node:
                result += self.next_node[node].below_sum(origin_word, word[1:])

            return result
        else:
            if word[0] in self.next_node:
                return self.next_node[word[0]].below_sum(origin_word, word[1:])
            else:
                return 0


def solution(words, queries):
    answer = []

    front_master_node = Node()
    back_master_node = Node()

    for word in words:
        front_master_node.mark(word, 0)
        back_master_node.mark(word[::-1], 0)

    for query in queries:
        query_type = get_query_type(query)

        if query_type == "back":
            answer.append(back_master_node.below_sum(query[::-1], query[::-1]))
        else:
            answer.append(front_master_node.below_sum(query, query))

    return answer


def get_query_type(query):
    if query[0] == "?" and query[-1] == "?":
        return "all"

    if query[0] == "?":
        return "back"

    return "front"


def main():
    words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    queries = ["fro??", "????o", "fr???", "fro???", "pro?"]

    solution(words, queries)


if __name__ == "__main__":
    main()
