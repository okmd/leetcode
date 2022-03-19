# You are given k sorted arrray i.e a element can exists at i-k or i+k.
# and use have to sort

# Method 1: Sort using merge sort O(nlogn)
# Method 2: Use insertion sort O(N*NK) = O(N^2k)
# Method 3: Using minheap for ascending and maxheap for descenging order.
# logk for push and pop
# N-k elements to push and pop = O(k) = heapify
# Total O(k) + (nlogk)
import heapq

# This solution will give correct ans only for valid k sorted array.
#### NOTE: WHY ACTUALLY THIS WORKING? ####
def using_heap(arr, k):
    # Idea is to maintain heap of size k+1
    # use heap sort.
    i = k+1
    # put first k+1 elements into the min heap.
    heap = arr[:i]
    heapq.heapify(heap)
    ans = []
    # keep on adding and removing from the queue to get the sorted array
    # push and pop take O(logk) as the heap size is of k
    while len(arr) > i:
        ele = heapq.heappop(heap)
        ans.append(ele)
        heapq.heappush(heap, arr[i])
        i += 1
    # remaining are sorted.
    # min to max pop form the minheap
    while len(heap):
        ans.append(heapq.heappop(heap))
    return ans


# Other variation is checking weahter the array is k sorted or not.

def ksorted2(arr, k):
    aux = [(arr[i], i) for i in range(len(arr))]
    aux.sort(key=lambda k:k[0])
    # check if any element is is perent more than k distance
    for i in range(len(aux)):
        if abs(aux[i][1]-i)>k:
            return False
    return True


# arr = [24, 25, 35, 13, 37, 42, 4, 27, 16, 7, 10, 32, 41, 6] #7, no
arr = [3, 21, 41,5, 38, 7, 37, 2, 13, 40, 17, 34]#3 no
# arr = [3,2,1,5,6,4]
k = 3
print(using_heap(arr, k))
print(ksorted(arr, k))
print(ksorted2(arr, k))
