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