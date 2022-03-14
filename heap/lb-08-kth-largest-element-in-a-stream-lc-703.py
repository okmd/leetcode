# design a class to find the kth largest element in sorted order not kth distinct element.
import heapq
# https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest:
    def __init__(self, k, nums):
        self.k = k
        self.heap = nums
        # create heap out of nums
        heapq.heapify(self.heap)
        # remove all elements and maintain only k element minheap
        while len(self.heap)>k:
            heapq.heappop(self.heap)
        

    def add(self, val):
        # add to heap
        heapq.heappush(self.heap, val)
        # if push the element and remove only if heap size increase beyond k
        # otherwise it will raise error is no element is present
        if len(self.heap) > self.k:
            heapq.heappop(self.heap)
        return self.heap[0]
