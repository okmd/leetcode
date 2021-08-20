# counting sort is used when the numbers are in specific range.
# step 1: Find frequency.
# step 2: Find cumulative frequency.
# step 3: Start from either left or right in original array, value at index 'element' gives the 'position' or index in original sorted array.
# Time complexity: O(range + N)
# range = 0..9, N = numbers of elements.

def counting_sort(number_range, arr):
    frequency = [0]*number_range
    sorted_array = [0]*len(arr)
    # find frequency
    for i in arr:
        frequency[i] += 1
    # find cumulative frequency
    # cumulative value at index i represents the number of elements placed till index i in sorted array.
    for i in range(1, number_range):
        # for decreasing oder take frequency from right hand side
        # i = number_range - i - 1
        frequency[i] += frequency[i-1]
    # for each element in array, cumulative frequency gives how many elements are present before this elements.
    # but this is 0 based indexing hence this will be placed at (cum_feq - 1).
    # reduce the current frequency as this element is already placed.
    for ele in arr:
        frequency[ele] -= 1
        sorted_array[frequency[ele]] = ele

    return sorted_array


if __name__ == "__main__":
    elements = [3, 4, 5, 0, 2, 6, 0, 22, 1, 6, 4, 3, 11]
    k = max(elements) - min(elements) + 1
    # This method is usefull when the range is short and numbers of elements are large.
    # time complexity will be ~O(n) = O(k+n)
    print(counting_sort(k, elements))

    # NOTE: if the range if other than o to k then it can be normalized to make 0-k range range by adding or subtacting value.
    # e.g range 10-90 = 91 elements
    # normalized subtract 10 from each element = 0-80 = 91 elements
    # 10^3 - 10^5 = then subtract by 10^3
    # if -a to b then add +a to make 0 to a+b
