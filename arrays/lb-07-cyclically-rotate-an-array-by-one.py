def rotate(arr, n):
    # store last element
    temp = arr[n-1]
    # move right
    for i in range(n-1, 0, -1):
        arr[i] = arr[i-1]
    # make last ans first
    arr[0] = temp
    return arr

arr = [1,2,3,4,5]
n = len(arr)    
print(rotate(arr, n))