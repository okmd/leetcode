def shuffle(self, nums: List[int], n: int) -> List[int]:
    l = []
    for i,j in enumerate(range(n,2*n)):
        l.append(nums[i])
        l.append(nums[j])
    return l