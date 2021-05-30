# Given an array of elements.
# find all subarray of size k,
# Max/Min sum of each subarray.
# either print or return array.
def max_sum_subarray_brute(arr, k):
    # O(n**2)
    mx_sums = []
    for i in range(len(arr)-k+1):
        sm = 0
        for j in range(i, i+k):
            sm += arr[j]
        mx_sums.append(sm)
    return mx_sums
            
            
def max_sum_subarray_optimized(arr, k):
    # O(n)
    # using Q, Sliding window technique
    i, j = 0,0
    mx_sums=[]
    sm = 0
    while j<len(arr):
        sm+=arr[j]
        if j-i+1<k:
            j+=1 
        elif j-i+1==k:
            mx_sums.append(sm)
            sm-=arr[i]
            i+=1
            j+=1
    return mx_sums


if __name__=="__main__":
    arr = [1,3,-1,-3,5,3,6,7]
    k = 3
    print(max_sum_subarray_brute(arr, k))
    print(max_sum_subarray_optimized(arr, k))