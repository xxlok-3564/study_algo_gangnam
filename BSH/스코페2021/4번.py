import sys


class Node:
    converted_score = {"Y": 0, "O": 1, "W": 2}

    def __init__(self, width, height):
        self.width = width
        self.height = height

        self.mark = None
        self.preference = None
        self.opened_score = None

    def mark_opened(self, is_opened):
        self.opened_score = self.converted_score[is_opened]

    def __repr__(self):
        return "(" + str(self.opened_score) + " | " + str(self.preference) + ")"


def main():
    kind_of_score = "ABCDE"
    scores = list(map(float, sys.stdin.readline().split()))
    score_dict = dict()
    reverse_score_dict = dict()
    for idx, char in enumerate(kind_of_score):
        score_dict[char] = scores[idx]
        reverse_score_dict[scores[idx]] = char

    # print(score_dict)

    height, width = map(int, sys.stdin.readline().rstrip().split())

    nodes = list()

    for h in range(height):
        is_opened = sys.stdin.readline().rstrip()
        for w in range(width):
            new_node = Node(w, h)
            new_node.mark_opened(is_opened[w])
            nodes.append(new_node)

    for h in range(height):
        content_types = sys.stdin.readline().rstrip()
        for w in range(width):
            node_idx = w + h * width
            converted_score = score_dict[content_types[w]]

            nodes[node_idx].mark = content_types[w]
            nodes[node_idx].preference = converted_score

    nodes.sort(key=lambda n: (n.opened_score, -n.preference, n.height, n.width))

    # print(nodes)

    for node in nodes:
        if node.opened_score == 2:
            break

        print(node.mark, node.preference, node.height, node.width)


if __name__ == '__main__':
    main()
