def numIdenticalPairs(self, nums: List[int]) -> int:
    cnt = 0
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]==nums[j]:
                cnt+=1
    return cnt