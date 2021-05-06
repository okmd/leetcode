def decompressRLElist(self, nums: List[int]) -> List[int]:
    lst = []
    for i in range(0, len(nums), 2):
        freq = nums[i]
        val = nums[i+1]
        for j in range(freq):
            lst.append(val)
    return lst