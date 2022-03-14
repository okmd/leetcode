# Given k sorted lists
# merge using heap min heap or priority queue
# take first k elements of all the lists and build heap.
# extract min, and add next smallest element and advance pointer.
# do the same thing for complete lists
# O(NlogK) = >N of elements, K= number of lists, Build heap O(K)
import heapq
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __lt__(self, other):
        return self.val < other.val

def merge_k_sorted_lists(lists):
    head = temp = ListNode(0)
    heap = []
    for lst in lists:
        if lst:
            heapq.heappush(heap, (lst.val, lst))
    while len(heap):
        val, node = heapq.heappop(heap)
        temp.next = ListNode(val)
        temp = temp.next
        node = node.next
        if node:
            heapq.heappush(heap, (node.val, node))
    return head

                



l1 = ListNode(1)
l1.next = ListNode(4)
l1.next.next = ListNode(5)

l2 = ListNode(1)
l2.next = ListNode(3)
l2.next.next = ListNode(4)

l3 = ListNode(2)
l3.next = ListNode(6)
lists = [l1, l2, l3]

merged = merge_k_sorted_lists(lists)
# setattr(Node, "__lt__", lambda self, other: self.data < other.data)
# if node class is not accessible
while merged:
    print(f"{merged.val}", end="->")
    merged = merged.next
print("NULL")
