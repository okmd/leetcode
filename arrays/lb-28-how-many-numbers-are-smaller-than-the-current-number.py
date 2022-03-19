def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
    cnts=[]
    for i in range(len(nums)):
        cnt = 0
        for j in range(len(nums)):
            if i==j:
                continue
            else:
                if nums[i]>nums[j]:
                    cnt+=1
        cnts.append(cnt)
    return cnts
    