from math import ceil, floor
# This sort is used when the data is uniform and can be divided into k bucket.
# Each bucket will have the same number of data points at each bucket if uniform.
# If size of each bucket is fixed then number of bucket = {max(array) - min(array)} / size of each bucket.
# relative conversion, bucket no. = {value - min(array)} / bucket size. starting point of bucket = min(array)

# each bucket maintain a sorted linked list
# start from initial


def get_bucket(value, start, bucket_size):
    # relative distance = value - start
    # divide this distance to bucket size each.
    # x--------5(x+5), starting=x, actual=x+5, realtive = 5 = x+5 - 5
    # now divide this into group of 4 so it will go to group 1, 1-4 = group 0, 5-8 = group 1 ....
    return floor((value - start)/bucket_size)


def bucket_sort(arr, num_of_buckets):
    starting = min(arr)
    ending = max(arr)
    # all elements will be in between starting and ending, so elements range is end-start + 1
    bucket_ragne = ending - starting + 1
    # size of each bucket
    bucket_size = ceil(bucket_ragne/num_of_buckets)
    # create bucket which is list of lists.
    buckets = [[] for _ in range(num_of_buckets)]
    for ele in arr:
        # add element to bucket
        pos = get_bucket(ele, starting, bucket_size)
        buckets[pos].append(ele)
        # insertion sort on bucket.
        i = len(buckets[pos])-1
        temp = buckets[pos][i]
        while i > 0 and temp < buckets[pos][i-1]:
            buckets[pos][i] = buckets[pos][i-1]
            i -= 1
        buckets[pos][i] = temp
    # print the values of each bucket.
    sorted_array = []
    for i in range(num_of_buckets):
        for val in buckets[i]:
            sorted_array.append(val)

    return sorted_array


if __name__ == "__main__":
    tests = [[5, 1, 12, 10, 2, 6, 8],[4, 5, 3, 2, 5, -1],[94, -95, 300, 892, 885, -71],[4, 85, 43, 278, 905, 8071],[i for i in range(50)]]
    sizes = [3,4,6]
    for size in sizes:
        for test in tests:
            print(bucket_sort(test, size))
