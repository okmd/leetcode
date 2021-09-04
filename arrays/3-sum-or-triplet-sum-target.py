# You are given the array of numbers and a target.
# You need to find triplet sum = target
# Provided all element should be unique i.e can't use element at index i two time.
# Brute force try all triplets -> O(n**3)
# to maintain a set data structure for unique O(logn) - insert elements
# so O(n^3logn)
# Method 2:O(n^2log m) m=unique triplets, space: O(m)+O(n)
def triplet_sum(nums, target):
    # the idea is to maintain dict count of all occuring element
    # check is a+b+c = target => c = target-(a+b) exists or not in map
    # if yes the store it into the answer set
    answer_triplets = set()
    count_dict = dict()
    for i in nums:
        if not count_dict.get(i, None):
            count_dict[i] = 0
        count_dict[i] += 1
    # for each pair find c if exits in if yes then triplet is present
    for i in range(len(nums)):
        count_dict[nums[i]] -= 1  # remove
        for j in range(i+1, len(nums)):
            count_dict[nums[j]] -= 1  # remove
            if count_dict.get(target - (nums[i] + nums[j]), None):
                answer_triplets.add(
                    tuple(sorted([nums[i], nums[j], target - (nums[i]+nums[j])])))

            count_dict[nums[j]] += 1  # insert back

        count_dict[nums[i]] += 1  # insert back
    return list(answer_triplets)


def optimization(nums, target):
    # idea here to fix first element ad use two pointer technique to obtain other two elements then a+b+c = target
    # sorting the array so that element are  in inorder and duplicate triblet can be removed.
    nums = sorted(nums)  # O(nlog n)
    result = []
    # pick the first element of triplet from 0 to n-3 only as n-2, n-2 can form triplet.
    for i in range(len(nums)-2):
        # fix a, so we need to find b+c = target-a same as pair sum
        if i == 0 or (i > 0 and nums[i] != nums[i-1]):
            # set low to next element
            low = i+1
            # high to last element
            high = len(nums) - 1
            # now required sum is target- (a+b)
            sm = target-nums[i]  # as fist element is fixed
            # do as soon as low<high
            while low < high:
                # if sum found then add to result
                if nums[low] + nums[high] == sm:
                    result.append([nums[i], nums[low], nums[high]])
                    # skip all duplicate elements for remove duplicate triplet
                    while low < high and nums[low] == nums[low+1]:
                        low += 1
                    # skip all duplicate from right 
                    while low < high and nums[high] == nums[high-1]:
                        high -= 1
                    # use next element to consider, non unique
                    low += 1
                    high -= 1
                # if sum not found but sum is less then advance the left pointer as array is sorted
                elif (nums[low] + nums[high] < sm):
                    low += 1
                # else advance the right pointer.
                else:
                    high -= 1
        return result
    # time complexity = O(n) + O(nlog n) = O(nlogn)


nums = [-1, 0, 1, 2, -1, 4]
k = 0
print(triplet_sum(nums, k))
print(optimization(nums, k))
