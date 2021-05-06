def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
    lst = []
    for i,v in zip(index, nums):
        lst.insert(i, v)
    return lst