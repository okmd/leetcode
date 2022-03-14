# Given string and you need to sort according to the frequency of chars.
# The idea is to maintain a max heap
# sort max heap then return
import heapq
def sort_frequently(string):
    count = {}
    # find frequency of each char and store
    for i in string:
        if not count.get(i, None):
            count[i] = 0
        count[i] += 1
    
    # convert to list to heapify based on count
    heap = [(c,v) for (v,c) in count.items()]
    print(heap)
    # create a max heap
    heapq._heapify_max(heap)
    ans = []
    while len(heap):
        c, val = heapq._heappop_max(heap)
        # same char freq times.
        while c:
            c-=1
            ans.append(val)
    return "".join(ans)




string = "Aabb"
print(sort_frequently(string))