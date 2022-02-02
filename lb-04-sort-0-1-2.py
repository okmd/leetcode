def sort_012(nums):
    left = 0
    right=len(nums)-1
    mid = 0
    #split like till mid we have 0
    # mid to right = 1
    # right onwards = 2
    while mid<=right:
        if nums[mid]==0:
            # swap mid and left and now left have 0
            nums[left], nums[mid] = nums[mid], nums[left]
            # increase left to point to next location to be replaced for 0.
            left += 1
            # same for mid  1
            mid += 1
        # assign 2 from end and decrese only right as we can say anythig about the mid
        elif nums[mid] == 2:
            nums[right], nums[mid] = nums[mid], nums[right]
            right -= 1
        # if it is 1 then just skip and move mid ahead
        else:
            mid+=1
    return nums

num = [0,1,2,0,2,2,0,1,1,1,0]
print(sort_012(num))