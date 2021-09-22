# given running stram of numbers find median at any time.
# METHOD 1: maintain the sorted order using insertion technique. O(n^2)
# METHOD 2: Create max heap for left side and min heap for right side. O(nlogn)

import heapq
# NOTE: To utilize minheap as max heap push by changing the sign to -.


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.maxheap = []
        self.minheap = []

    def minTop(self):
        # first element is always the root.
        # arr[k] = arr[2k+1] and arr[2k+2]
        return self.minheap[0]

    def maxTop(self):
        return -self.maxheap[0]

    def addNum(self, num: int) -> None:
        # Helper functions #
        def maxPush(num):
            # as heapq is implemented as minheap, so use -1 to act as maxheap.
            heapq.heappush(self.maxheap, -num)

        def minPush(num):
            heapq.heappush(self.minheap, num)

        def minTomax(num):
            # pop from the min and put to max
            temp = heapq.heappop(self.minheap)
            minPush(num)
            maxPush(temp)

        def maxTomin(num):
            # pop from the min and put to max
            temp = heapq.heappop(self.maxheap)
            maxPush(num)
            # just make is +ve
            minPush(-temp)

        # Main Function #
        # if there is nothing in the array i.e left size max heap is empty
        if len(self.maxheap) == 0:
            maxPush(num)
        # otherwise if both have the same length then element should go to max heap with or without swapping.
        # swapping is required when element is less than right(minheap) hand side but want to into the left hand side(maxheap).
        elif len(self.maxheap) == len(self.minheap):
            if num < self.minTop():
                maxPush(num)
            else:
                minTomax(num)
        else:
            # if not equal but rhs is empty
            if len(self.minheap) == 0:
                # no element in the rhs so element will be inserted in rhs wether by swapping or direclty
                # swapping is required only when, elemement is less then max top. that want to enter in lhs.
                if num > self.maxTop():
                    minPush(num)
                else:
                    maxTomin(num)
            # adding greator elelemt will not change anything.
            elif num >= self.minTop():
                minPush(num)
            else:
                # want to enter into left but supposed to goto right then swap
                if num < self.maxTop():
                    maxTomin(num)
                # just enter into right.
                else:
                    minPush(num)

    def findMedian(self) -> float:
        # if length is odd then maxtop is the median
        if (len(self.maxheap) + len(self.minheap)) & 1:
            return self.maxTop()
        # for even both maxtop and mintop avg is median.
        return (self.maxTop() + self.minTop())/2


mf = MedianFinder()
mf.addNum(2)
mf.addNum(12)
mf.addNum(23)
mf.addNum(33)
mf.addNum(9)
print(mf.findMedian())
