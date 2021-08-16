# the idea is to sort and each time maximum element takes its original position.
# second max ...
# swapped with current and next element if not adequate.
# |unsorted | sorted|
def bubble_sort(arr):
    for i in range(len(arr)):
        flag = True # already sorted
        for j in range(0, len(arr)-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                flag = False
        # if any of subarray is sorted the don;t sort again.
        #  dry run 1,2,3,9,7,6
        if flag:
            break

    return arr


if __name__ == "__main__":
    print(bubble_sort([4, 5, 3, 2, 5, -1]))
    print(bubble_sort([94, -95, 300, 892, 885, -71]))
    print(bubble_sort([4, 85, 43, 278, 905, 8071]))
    print(bubble_sort([i for i in range(100)]))
