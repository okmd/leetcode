# Soting insertion comes handy when we are required to maintain the sorted list at
# any point of time like, finding median from stream
# Brute force
# for each element inserted sort the array = O(n*nlogn)

# optimization is insertion sort
def insertion_sort(arr, ele):
    # assume arr is already sorted
    i = len(arr)
    arr.append(ele)
    while i > 0 and arr[i] < arr[i-1]:
        arr[i], arr[i-1] = arr[i-1], arr[i]
        i -= 1

def find_median(arr, ele):
    insertion_sort(arr, ele)
    n = len(arr)
    if n&1:
        return arr[n//2]
    return (arr[n//2 - 1] + arr[(n//2)])/2


if __name__ == "__main__":
    arr = []
    elements = [5, 3, 7, 8, 9, 2, 4, 9, 0]
    for i in elements:
        insertion_sort(arr, i)

    for i in arr:
        print(i, end=" ")
    print()

    arr = []
    for i in elements:
        print(f"Median at {i}: ", find_median(arr, i))

