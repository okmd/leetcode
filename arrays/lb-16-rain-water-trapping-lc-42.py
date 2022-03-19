# Find the trapped water on the top of buildings.
# NOTE: Idea is to maintain 2 MIS and MDS. to store next left and right height.
def rain_water(heights):
    # find left max
    i = 1
    n = len(heights)
    left_heights = [0]
    left_max = heights[0]
    while i < n:
        left_heights.append(left_max)
        left_max = max(left_max, heights[i])
        i += 1

    i = n-2
    right_heights = [0]
    right_max = heights[n-1]
    while i >= 0:
        right_heights.insert(0, right_max)
        right_max = max(right_max, heights[i])
        i -= 1
    # print(left_heights)
    # print(right_heights)
    # print(heights)
    water = 0
    for i in range(len(heights)):
        w = min(left_heights[i], right_heights[i]) - heights[i]
        if w>0:
            water+=w
    return water


def optimization_2_pointer(heights):
    n = len(heights)
    if n<=2:
        return 0
    # not starting from extreme left or right because it will not store water.
    left, right = 1, n-2
    left_max = heights[0]
    right_max = heights[n-1]
    # if left_max > right_max fill from right else left.
    water = 0
    while left<=right:
        if left_max<=right_max:
            w = left_max - heights[left]
            left_max = max(left_max, heights[left])
            left += 1
        else:
            w = right_max - heights[right] 
            right_max = max(right_max, heights[right])
            right -= 1
        water += w if w>0 else 0
    return water







heights=[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(rain_water(heights))
print(optimization_2_pointer(heights))
