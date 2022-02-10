from linkedlist import LL

# combining each time two lists into a single list n-1 times.
# resultant list will be sorted list
# merge will merge two lists into single sorted list.
def method1(lists):
    if not len(lists):
        return lists

    resultant = lists[0]
    for i in lists[1:]:
        resultant = resultant.merge_iterative(i)
    return resultant


if __name__ == "__main__":
    values = [[1, 5, 9], [2, 4, 8], [2, 6], [1, 7]]
    n = len(values)
    lists = [LL() for _ in range(n)]

    for lst, vals in zip(lists, values):
        for i in vals:
            lst.insert(i)

    for i, lst in enumerate(lists):
        print(f"List {i+1}: ", end="")
        lst.show()

    print("Single sorted array: ", end="")
    method1(lists).show()
