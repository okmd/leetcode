from math import log, ceil
# radix sort is used to sort numbers large numbers i.e more digits.
# this can be used to sort any base number i.e decimal, binary etc
# use counting sort to sort each ith place digits of each number.
# Take an array start from LSB and add it to another array and sort original number with respect to this digit place.
# Time complexity: O(logb (max) * (n+k)) = O(max_digits *(n+k))
# Best input for which this will be linear time sort.
# d = logb(max) = number of digits in base b. if max = b^c then b = c i.e constant.
#  O(c*(n+k)) = O(n)

# step 1: find maximum in array
# step 2: d = log(max) = numbers of digits
# step 3: take 1th digit or LSB by using n%10
# e.g abcd -> to get b i.e at index 2 from LSB do abcd % b^index-1 for 1 based index


def get_num_of_digits(num, base):
    k = ceil(log(num, base))
    return k+1 if not num % base else k


def get_ith_digit(num, i, base):
    return (num // (base**i)) % base


def get_cum_frequency(arr, base):
    # as digits at any place will range only 0..9 or 0..base-1
    frequency = [0]*base
    frequency = [frequency[i]+1 for i in arr]
    frequency = [frequency[i]+frequency[i-1] for i in range(1, base)]
    for j in arr:
        frequency[j] += 1
    for j in range(1, base):
        frequency[j] += frequency[j-1]

    return frequency


def radix_sort(arr, b=10):
    maximum_element = max(arr)
    k = get_num_of_digits(maximum_element, b)
    sorted_array = [0]*len(arr)
    for i in range(k):
        counting_sort_array = []
        # get the LSB to MSB bits array at index i
        for ele in arr:
            ith_digit = get_ith_digit(ele, i, b)
            counting_sort_array.append(ith_digit)
        # sort original array
        frequency = get_cum_frequency(counting_sort_array, b)
        # place the original array value in sorted array based on ith index value
        for ele in arr[::-1]:
            ith_digit = get_ith_digit(ele, i, b)
            frequency[ith_digit] -= 1
            sorted_array[frequency[ith_digit]] = ele
        # overwrite the original array to sorted array.
        arr = sorted_array
    # return the sorted array
    return sorted_array


if __name__ == "__main__":
    elements = [170, 45, 75, 90, 802, 24, 2, 66]
    print(radix_sort(elements))
    elements = [100, 200, 500, 300, 150]
    print(radix_sort(elements))
    # binary
    elements = [100, 10, 1000, 11, 101]
    print(radix_sort(elements, 2))
    # octal
    elements = [777, 210, 211, 1, 501]
    print(radix_sort(elements, 8))
