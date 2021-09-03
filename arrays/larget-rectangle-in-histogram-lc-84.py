# The heights of the bar are given and the you need to find the
# Area of largest rectangle which can be formed using this bars.

# NOTE:
# It is observed that each rectangle include atleast on bar completely.
# So if we find the rectangle for each bar full included then
# takeout the maximum of the areas which will be the maximum area rectangle.
# To make a rectangle including ith rectangle completely.
# find the rectangle < left of it else 0
# find the rectanlge < right of it else n-1
## area = (right-left + 1)*height
# max(all such areas) = max rectangle area.
# Extra stack is required to maintain previous less hight bar.

# NOTE: Brute force finding left and right for each histogram = O(n**2)
# 3PASS
def largest_rectanlge_histogram(heights):
    # O(n) for finding left bar < ith bar.
    # O(n) for finding right bar < ith bar.
    # at the same time taking maximum.
    # So, O(n) time and space.
    stack = [0]
    n = len(heights)
    # for left bar
    left_bars = [0]
    for i in range(1, n):
        while len(stack) and heights[stack[-1]] > heights[i]:
            top = stack.pop()

        if len(stack) == 0:
            left_bars.append(0)
        else:
            left_bars.append(stack[-1]+1)
        stack.append(i)

    # for right
    stack = [n-1]
    right_bars = [n-1]
    for i in range(n-2, -1, -1):
        while len(stack) and heights[stack[-1]] >= heights[i]:
            top = stack.pop()

        if len(stack) == 0:
            right_bars.insert(0, n-1)
        else:
            right_bars.insert(0, stack[-1]-1)
        stack.append(i)

    max_area = 0
    for i in range(n):
        max_area = max(
            max_area, (right_bars[i] - left_bars[i] + 1) * heights[i])
    # Or this can be applied inside the right loop to calculate max.

    return max_area

# 2PASS
def optimization(heights):
    n = len(heights)
    stack_left = [0]
    stack_right = [n-1]
    left_bars = [0]
    right_bars = [n-1]

    # for left bar

    for i in range(1, n):
        # left
        while len(stack_left) and heights[stack_left[-1]] > heights[i]:
            top = stack_left.pop()

        if len(stack_left) == 0:
            left_bars.append(0)
        else:
            left_bars.append(stack_left[-1]+1)
        stack_left.append(i)
        # right
        while len(stack_right) and heights[stack_right[-1]] >= heights[n-i-1]:
            top = stack_right.pop()

        if len(stack_right) == 0:
            right_bars.insert(0, n-1)
        else:
            right_bars.insert(0, stack_right[-1]-1)
        stack_right.append(n-i-1)

    # for right

    max_area = 0
    for i in range(n):
        max_area = max(
            max_area, (right_bars[i] - left_bars[i] + 1) * heights[i])
    # Or this can be applied inside the right loop to calculate max.

    return max_area

# 1PASS = Time and space = O(n)
def optimization2(heights):
    # Idea is to maintain a MIS
    # at any point if left element is >= current element then for pervious element
    # right smaller is itself, and width is i as i-0 = i
    # if left element is < current element the just push to the stack
    max_area = 0
    stack = []
    n = len(heights)
    for i in range(n+1):
        # due to or i==n the index does not go out of index
        while len(stack) and (i == n or heights[stack[-1]] >= heights[i]):
            height = heights[stack.pop()]
            if len(stack):
                width = i - stack[-1] - 1
            else:
                width = i  # as i-0 is i
            max_area = max(max_area, width*height)
        stack.append(i)
    return max_area


def same_as_optimization2(heights):
    max_area = 0
    i = 0
    j = 0
    stack = []
    while i < len(heights):
        if len(stack) == 0:
            stack.append([0, heights[i]])
            i += 1
            j = i
        elif heights[i] >= stack[-1][1]:
            stack.append([j, heights[i]])
            i += 1
            j = i
        else:
            top = stack.pop()
            j = top[0]
            max_area = max(max_area, top[1]*(i-j))

    while len(stack):
        top = stack.pop()
        max_area = max(max_area, top[1]*(i-top[0]))

    return max_area


heights = [2, 1, 5, 6, 2, 3]
print(largest_rectanlge_histogram(heights))
print(optimization(heights))
print(optimization2(heights))
print(same_as_optimization2(heights))
