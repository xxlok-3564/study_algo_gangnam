import sys


def main():
    total = 0
    kind_of_tree_set = set()
    count_trees = dict()

    for line in sys.stdin:
        total += 1
        input_tree = line.rstrip()
        kind_of_tree_set.add(input_tree)

        if input_tree in count_trees:
            count_trees[input_tree] += 1
        else:
            count_trees[input_tree] = 1

    for tree_name in sorted(kind_of_tree_set):
        print(tree_name, "{:.4f}".format(count_trees[tree_name] / total * 100))


if __name__ == "__main__":
    main()
