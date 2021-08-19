from linkedlist import LL
import heapq

# method 4: divide and conquer
# divide lists into subpart of of size 2, same as merge sort
# O(nlog k), k=number of linked list, n = nums of nodes in all the sublists
# if odd numbero of lists are there then stop if only one list is present
# merge to sublists to obtain sorted list
def sort(lists, l, r):
    if r-l==1:
        return lists[l].merge_iterative(lists[r])
    mid = l+ (r-l)//2
    left = sort(lists, l, mid)
    right = sort(lists, mid+1, r)
    return left.merge_iterative(right)


def method4(lists):
    return sort(lists, 0, len(lists)-1)


# Method 5: Heap
# take an array and store head of all lists
# push all k lists head into heap
# pop min from heap and inser to ll
# update head pointer and push all non null nodes.
# push/pop = log(k)
# O(nlogk)


def method5(lists):
    n = len(lists)
    heads =[None]*n
    minheap = []
    for i in range(n):
        if lists[i].head:
            heads[i] = lists[i].head
            heapq.heappush(minheap, heads[i].value)
            heads[i] = heads[i].next

    root = LL()
    while len(minheap):
        min_ele = heapq.heappop(minheap)
        root.insert(min_ele)
        for i in range(n):
            if heads[i]:
                heapq.heappush(minheap, heads[i].value)
                heads[i] = heads[i].next
    return root



# summary
#  heap and divide and conquer = O(nlogk)
# simple solution = O(nk), O(nlogn)
# space O(1) for inplace else O(n)


if __name__ == "__main__":
    values = [[1, 5, 9], [2, 4, 8], [2, 6], [1, 7]]
    n = len(values)
    lists = [LL() for _ in range(n)]
    for lst, vals in zip(lists, values):
        for i in vals:
            lst.insert(i)

    for lst in lists:
        lst.show()

    print("Method4:(nlogk) ", end=" ")
    method4(lists).show()
    print("Method5:(nlogk) ", end=" ")
    method5(lists).show()

# PAuse 5.55
