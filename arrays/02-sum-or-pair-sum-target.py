# You are given nums and a target sum
# you need to find if pair of elements whose sum is target.

def pair_sum_target_or_2sum(nums, target):
    # Idea is to taverse the array one time.
    # Check if target-ele is already came earlier then pair found.
    # else push the ele into the set for future checking.
    elements_came = dict()
    for i, ele in enumerate(nums):
        found = elements_came.get(target - ele, None)
        print(target, ele, elements_came, found)
        if found!=None:
            return  [found, i]
        
        elements_came[ele] = i

n = [2,7,11,15]
t = 9

print(pair_sum_target_or_2sum(n,t))