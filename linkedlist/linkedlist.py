class Node:
    def __init__(self, val=0, next=None):
        self.value = val
        self.next = next


class LL:
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    def insert(self, val):
        node = Node(val)
        if not self.head:
            self.head = node
            self.tail = self.head
        else:
            self.tail.next = node
            self.tail = node

    def mid(self):
        if not self.head or not self.head.next:
            return self.head

        root = self.head
        slow, fast = root, root.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow

    def show(self):
        root = self.head
        while root:
            print(root.value, end="->")
            root = root.next
        print("None")

    def merge_iterative(self, ll2):
        a = self.head
        b = ll2.head
        result = LL()
        while a and b:
            if a.value < b.value:
                result.insert(a.value)
                a = a.next
            else:
                result.insert(b.value)
                b = b.next
        while a:
            result.insert(a.value)
            a = a.next
        while b:
            result.insert(b.value)
            b = b.next
        return result

    def sort(self):
        if not self.head or not self.head.next:
            return self
            
        mid = self.mid()
        temp = mid.next
        mid.next = None
        second = LL()
        while temp:
            second.insert(temp.value)
            temp = temp.next

        first = self.sort()
        second = second.sort()
        return first.merge_iterative(second)
        


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
