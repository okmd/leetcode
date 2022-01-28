# Given n request and c window size
# use lru replacement policy and find page fault

# Method: search element in window + move to the end : least to most recently used
# O(C^2)
# Use linkedlist to remove shifting
# Use dictionay to remove seaching 
# Combining both will give O(1)

def n2_method(arr, c):
    wind = [-1]*c
    fault = 0
    for ele in arr:
        # present in the cache
        if ele in wind:
            # change to most recently
            i = wind.index(ele)
            for j in range(i, c-1):
                wind[j] = wind[j+1]
        # not present in the cache
        else:
            for i in range(c-1):
                wind[i] = wind[i+1]
            # fault
            fault += 1
        # place at the end, most recent page
        wind[-1] = ele
                    
    return fault


class Node:
    def __init__(self, val, n=None, p=None):
        self.val = val
        self.next = n
        self.prev = p
        
# O(1)
def use_ll_and_dict(arr, c):
    present_in_window = dict() # contains the node address
    head = None
    tail = None
    fault = 0
    curr_len = 0
    for ele in arr:
        node = present_in_window.get(ele, None)
        if node:
            ## present in the map hence get address from here,
            # and re-arrange the links to make most recent, 
            # delete from its location and inser at the tail
            # as the node is present hence at-least head is present
            # if it is tail
            if node.next == None:
                continue
            #if it is head
            elif node.prev==None:
                node.next.prev = None 
                head = node.next 
                # tail.next = node 
                # node.prev = tail 
                # tail = node
                # tail.next = None 
            else:
                node.prev.next = node.next # if it is head
                node.next.prev = node.prev
            tail.next = node 
            node.prev = tail 
            tail = node
            tail.next = None 
        else:
            # not present in the cache hence add at the end
            if not head:
                head = Node(ele)
                tail = head
                curr_len+=1
            elif curr_len < c:
                temp = Node(ele)
                tail.next = temp
                tail.next.prev = tail 
                tail = temp
                curr_len += 1
            else:
                # not present and cache is full
                # remove from head and insert at the tail
                del present_in_window[head.val]
                head.next.prev = None
                head = head.next 
                tail.next = Node(ele)
                tail.next.prev = tail 
                tail = tail.next 
            present_in_window[ele] = tail
            fault += 1
    return fault
    
pages = [5,0,1,3,2,4,0,5]
c = 4
print(n2_method(pages, c))
print(use_ll_and_dict(pages, c))