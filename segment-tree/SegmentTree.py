class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.index = 1 # segment tree is 1 based
        self.tree = [0]*4*len(arr) # at max size of array to represent st would be 4n
        self.start = 0
        self.end = len(arr) - 1

    def build(self):
        def __helper(index, start, end):
            # outof bound
            if start > end:
                return
            # leaf node, unique element
            if start == end:
                self.tree[index] = self.arr[start]
                return
            # partition as merge sort
            mid = start + (end-start)//2
            __helper(2*index, start, mid)
            __helper(2*index+1, mid+1, end)
            # make tree as left + right, combination
            self.tree[index] = self.tree[2*index] + self.tree[2*index+1]

        __helper(self.index, self.start, self.end)

    def query(self, qs, qe):
        def __helper(qs, qe, index, start, end):
            # quried range is not overlapping with range
            if qs > end or qe < start:
                return 0
            # total overlapping
            if start >= qs and end <= qe:
                return self.tree[index]
            # partial overlapping
            mid = start + (end - start)//2
            left_sum = __helper(qs, qe, 2*index, start, mid)
            right_sum = __helper(qs, qe, 2*index+1, mid+1, end)
            return left_sum + right_sum

        return __helper(qs, qe, self.index, self.start, self.end)

    def update(self, pos, val):
        def __helper(index, start, end):
            if start > pos or end < pos:
                return
            if start == end:
                self.tree[index] = val
                return
            mid = start+(end-start)//2
            __helper(2*index, start, mid)
            __helper(2*index+1, mid+1, end)
            self.tree[index] = self.tree[2*index] + self.tree[2*index+1]

        self.arr[pos] = val
        __helper(self.index, self.start, self.end)

    def show(self):
        for val in self.tree:
            print(val, end=" ")
        print()



if __name__=="__main__":
    # Execution
    st = SegmentTree([1, 3, 2, -2, 4, 5])
    st.build()
    st.show()
    # range 2-4 means index 2 to index 4 in original array
    print(f"Range sum(2,4): {st.query(2,4)}")
    print(f"Range sum(1,4): {st.query(1,4)}")
    print(f"Range sum(3,3): {st.query(3,3)}")
    st.update(2, 100)
    st.show()
    print(f"Range sum(2,4): {st.query(2,4)}")
    print(f"Range sum(1,4): {st.query(1,4)}")
    print(f"Range sum(3,3): {st.query(3,3)}")
    # Applications
    # - Range sum query
    # - Range min/max query
    # - Range gcd/lcm query
    # - Range XOR query
    # - Count 0's in range or kth 0 with update query.
