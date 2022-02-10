
class Node:
    def __init__(self, val):
        self.value = val
        self.next = None


class LList:
    def __init__(self):
        self.head = None
        self.last = None

    def insert_at_head(self, val):
        if not self.head:
            self.head = Node(val)
            self.last = self.head
        else:
            node = Node(val)
            node.next = self.head
            self.head = node

    def print_ll(self):
        if self.detect_cycle():
            print("cycle is present.")
            return
        temp = self.head
        while temp:
            print(f"{temp.value}", end=" -> ")
            temp = temp.next
        print("None")

    def create_cycle(self, x):
        temp = self.head
        while temp and x > 1:
            temp = temp.next
            x -= 1
        self.last.next = temp

    def detect_cycle(self):
        slow, fast = self.head, self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return slow
        # cycle not present
        return 0

    def remove_cycle(self):
        slow = self.detect_cycle()
        # 2 x slow = fast
        if slow:
            entry = self.head
            while slow.next != entry:
                slow = slow.next
            slow.next = None
            print("Cycle removed.")
        else:
            print("Cycle is not present.")
    def reverse_list(self):
        prev = None
        curr = self.head
        while curr:
            nxt = curr.next
            curr.next = prev 
            prev = curr 
            curr = nxt 
        self.head = prev


if __name__ == "__main__":
    ll = LList()
    for i in range(4, -1, -1):
        ll.insert_at_head(i)
    ll.print_ll()
    # create cycle
    ll.create_cycle(1)
    ll.print_ll()
    ll.remove_cycle()
    ll.print_ll()
    ll.reverse_list()
    ll.print_ll()
