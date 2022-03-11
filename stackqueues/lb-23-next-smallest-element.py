def next_smallest(arr, n):
    # code here
    ans = [0]*n
    stack = []
    for i, val in enumerate(arr):
        if len(stack) == 0 or arr[stack[-1]] <= val:
            stack.append(i)
        else:
            j = i
            while j > 0 and len(stack) and val < arr[stack[-1]]:
                ans[stack.pop()] = arr[i]
                j -= 1
            stack.append(i)

    while len(stack):
        ans[stack.pop()] = -1
    return ans

arr = [4, 2, 1, 5, 3]
print(next_smallest(arr, len(arr)))