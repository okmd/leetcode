# Given an array find next greater element of each array.

def bruteforce(arr):
    nge = []
    for i in range(len(arr)):
        found = 0
        for j in range(i+1, len(arr)):
            if arr[i] < arr[j]:
                nge.append(arr[j])
                found = 1
                break
        if not found:
            nge.append(-1)
    return nge


def stackmethod(arr):
    stack = []
    nge = [0]*len(arr)
    # only insert less than or equal to top of the stack.
    stack.append(0)
    for i in range(1, len(arr)):
        if arr[stack[-1]] > arr[i]:
            stack.append(i)
        else:
            while len(stack) > 0 and arr[stack[-1]] < arr[i]:
                nge[stack.pop()] = arr[i]
            stack.append(i)
    # pop the remaining elements from the stack
    for i in stack:
        nge[i] = -1
    return nge


arr = [19, 6, 7, 20, 10, 15]
nge = bruteforce(arr)
print(f"Arr: {arr}, nge: {nge}")
nge = stackmethod(arr)
print(f"Arr: {arr}, nge: {nge}")

################### LC ####################
def next_greatest(arr, n):
    # code here
    # change to dict
    ans = [0]*n
    stack = []
    for i, val in enumerate(arr):
        if len(stack) == 0 or arr[stack[-1]] > val:
            stack.append(i)
        else:
            j = i
            while j > 0 and len(stack) and val > arr[stack[-1]]:
                ans[stack.pop()] = arr[i] # change to i
                j -= 1
            stack.append(i)

    while len(stack):
        ans[stack.pop()] = -1
    return ans
    # leetcode
    # for i in range(len(nums1)):
    # temp = ans[nums1[i]]
    # if temp!=-1:
    #     nums1[i] = arr[temp]
    # else:
    #     nums1[i] = temp

arr = [4, 2, 1, 5, 3]
print(next_greatest(arr, len(arr)))
