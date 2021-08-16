# in the selection sort idea is to pick the minimum element index form unsorted array and
# swap this element with with actual minimum from unsorted array
# |sorted | unsorted|
def selection_sort(arr):
    for i in range(len(arr)-1):
        min_ele_index = i
        for j in range(i+1, len(arr)):
            if arr[min_ele_index] > arr[j]:
                min_ele_index = j
        arr[i], arr[min_ele_index] = arr[min_ele_index], arr[i]
    return arr


if __name__ == "__main__":
    print(selection_sort([4, 5, 3, 2, 5, -1]))
    print(selection_sort([94, -95, 300, 892, 885, -71]))
    print(selection_sort([4, 85, 43, 278, 905, 8071]))
