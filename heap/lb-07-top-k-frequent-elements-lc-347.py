# Find top k-frequent elements.
# Create a max heap of count of elements of size k
# pop k element and return.
import heapq

def top_k_frequent(nums, k):
    count_dict = {}
    for i in nums:
        if not count_dict.get(i, None):
            count_dict[i] = 0
        count_dict[i] += 1
    heap = [(c, v) for (v, c) in count_dict.items()]
    # print(heap)
    heapq._heapify_max(heap)
    # print(heap)
    ans = []
    while len(heap) and k:
        k-=1
        ans.append(heapq._heappop_max(heap)[1])
    return ans


nums = [1,1,1,2,2,3]
k = 2
print(top_k_frequent(nums, k))
