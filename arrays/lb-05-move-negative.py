# Move all negative numbers to beginning and positive to end with constant extra space
def move(arr):
    l = 0
    r = len(arr) - 1
    while l<=r:
        if arr[l]<0:
            l+=1
        else:
            arr[r], arr[l] = arr[l], arr[r]
            r -= 1
    return arr


arr = [-12, 11, -13, -5, 6, -7, 5, -3, 11]
print(move(arr))