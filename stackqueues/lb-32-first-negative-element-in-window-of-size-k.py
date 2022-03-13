# Given an array of elements.
# find all subarray of size k,
# first -ve of each subarray.
# either print or return array.
def first_negative_subarray_brute(arr, k):
    # O(n**2)
    negative_k = []
    for i in range(len(arr)-k+1):
        found = 0
        for j in range(i, i+k):
            if arr[j]<0:
                found = arr[j]
                break
        negative_k.append(found)
    return negative_k
            
            
def first_negative_subarray_optimized(arr, k):
    # O(n)
    # using Q, Sliding window technique
    i, j = 0,0
    fst_neg=[]
    Q = []
    while j<len(arr):
        if arr[j]<0:
            Q.append(arr[j])
        if j-i+1<k:
            j+=1 
        elif j-i+1==k:
            if len(Q)==0:
                fst_neg.append(0)
            else:
                fst_neg.append(Q[0])
            if len(Q) and Q[0] == arr[i]:
                del Q[0]
            i+=1
            j+=1
            
    return fst_neg


if __name__=="__main__":
    arr = [1,3,-1,-3,5,3,6,7]
    k = 3
    print(first_negative_subarray_brute(arr, k))
    print(first_negative_subarray_optimized(arr, k))