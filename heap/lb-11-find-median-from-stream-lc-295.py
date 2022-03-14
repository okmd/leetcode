# You are given stream of numbers and u need to find median at any point of time.
# idea is to maintain the sorted array and then find median in O(1) time.

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []
        
    def addNum(self, num: int) -> None:
        # add number to list 
        self.append(num)
        # get the index of newly inserted element
        i = len(self.arr) - 1
        # get that element=num
        ele = self.arr[i]
        # as the array is sorted hence
        # move and place this value in this place
        # if this element is less than previos 
        # keep moving right till its location
        while i>0 and ele<self.arr[i-1]:
            self.arr[i] = self.arr[i-1]
            i-=1
        # no place element to its location
        # if already sorted then no change.
        self.arr[i] = ele
        

    def findMedian(self) -> float:
        # as the array is sorted
        # if odd then middle is median
        # else avg of two mid elements
        n = len(self.arr)
        if n&1:
            return self.arr[n//2]
        return (self.arr[n//2 - 1] + self.arr[n//2])/2


## Optimization using heap.
# Try creating 2 heaps max and min.
# at any time max heap will contain median at root is n is odd.
# and avg of root of max and min heap is median if n is even.
# | max heap | min heap | spilt the numbers into two parts.
# TODO:
class MedianFinderHeap:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_heap = []
        self.max_heap = []
        
    def addNum(self, num: int) -> None:
        pass
        

    def findMedian(self) -> float:
        pass