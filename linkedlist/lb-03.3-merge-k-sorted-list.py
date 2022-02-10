from linkedlist import LL

def method2(lists):
    # time O(nk), space O(n) or O(1)
    # create an array of heads of all the lists
    n = len(lists)
    heads = [None]*n
    for i in range(n):
        heads[i] = lists[i].head
    # now pick min from each array in and buid the new list or just change the pointer
    root = LL()

    while True:
        min_val = 1000
        elements_exists = False
        for i in range(n):
            if heads[i] and min_val > heads[i].value:
                min_val = heads[i].value
                min_index = i
                elements_exists = True

        if elements_exists:
            heads[min_index] = heads[min_index].next
            root.insert(min_val)
        else:
            break

    return root


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
    method2(lists).show()
