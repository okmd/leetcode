def first_node(head):
    # assume that cycle is present
    # Find the meeting point, it may not be the first node
    slow, fast = head, head
    while fast and fast.next:
        slow = slow.next 
        fast = fast.next.next 
        if slow==fast:
            break
        
    # find the first point 
    # start from head again and move from meeting point
    # you will meet at the first point
    fast = head
    while fast != slow:
        slow = slow.next 
        fast = fast.next 
    # it is the first node so return
    return slow
    