# Given a permutation of n numbers,
# the task is to generate the next permutation from current one
# such that the next permutation is greator than current one.
# if not then return it numbers in ASC.
# STEPs: 1 3 5 4 2 -> 1 4 2 3 5
#   From right to left find a[i] < a[i+1] = index1= 1(ele = 3)
#   From right to index1 a[index2] > a[index1] = index2= 3( ele = 4)
#   Swap(a[index1], a[index2]) = 1, 4, 5, 3, 2
#   reserve(index1 + 1, last) = 1 4 2 3 5
# NOTE: Idea is to chage the low value of high weightage with high value of low weightage.
#       And sort the array after that changed index so that we get min value, next-perm.

def next_permutation(nums):
    n = len(nums)
    if n == 1:
        return
    right_most_peak = -1
    i = n-1
    while i >= 0:
        if nums[i] > nums[i-1]:
            right_most_peak = i-1
            break
        i -= 1
    if right_most_peak == -1:
        # already descending order
        # just reverse it
        for i in range(n//2):
            nums[i], nums[n-i-1] = nums[n-i-1], nums[i]
        return
    i = n-1
    while right_most_peak <= i:
        if nums[i] > nums[right_most_peak]:
            next_greator_element = i
            break
        i -= 1
    nums[right_most_peak], nums[next_greator_element] = nums[next_greator_element], nums[right_most_peak]
    nums[right_most_peak+1:] = sorted(nums[right_most_peak+1:])


perm = [1, 3, 2]
next_permutation(perm)
print(perm)
