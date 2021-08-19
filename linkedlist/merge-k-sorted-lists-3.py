from linkedlist import LL

# Method 3:
# find tail O(k) of each list or maintain in node O(1).
# combine all the sublists into a single list
# apply merge sort on complete list = O(nlogn)

def method3(lists):
    n = len(lists)
    for i in range(n-1):
        lists[i].tail.next = lists[i+1].head
    return lists[0].sort()


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
    method3(lists).show()


