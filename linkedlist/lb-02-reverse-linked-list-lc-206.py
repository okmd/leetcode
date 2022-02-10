# There reverse using recursion and iteration.

def recursive(head):
    if not head:
        return head

    def rev(node, prev):
        if not node:
            head = prev
            return head
        head = rev(node.next, node)
        node.next = prev
        return head

    return rev(head, None)


def iterative(head):
    if not head:
        return head
    temp = head
    prev = None
    curr = head
    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp

    return prev
