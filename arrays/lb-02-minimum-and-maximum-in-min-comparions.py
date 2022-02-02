# Given n elements find min and max in minimum compasrions
# Simple search:
#   Take 1st as min and max for remaining 2*(n-1) OR
#   Take 1st as min and max, 2nd in 1 comparison then 2*(n-2) = 1 + 2*(n-2)
# Worst:    1 + 2(n-2)
# Best:     1 +  (n-2)
def basic(arr):
    n = len(arr)
    if n==1: # 0 comp
        return arr[0], arr[0]
    if n==2: # 1 comparison
        return (arr[1], arr[0]) if arr[1]<=arr[0] else (arr[0], arr[1])
    # more than 2 elements => 1 comp
    mn,mx = (arr[1], arr[0]) if arr[1]<=arr[0] else (arr[0], arr[1])
    for ele in arr[2:]:
        # 2 comp for n-2 each elements(n-2)
        if ele<=mn:
            mn = ele
        elif ele>mx:
            mx = ele
    return mn, mx


# Method 2: tournament method
# for more than 2 elements, divide into two parts and find min, and max of each part then combined min and max
# 3n/-2 comparisons if power of 2 else more than that
def tournament(arr, l, r):
    n = r - l + 1
    if n==1:
        return arr[l], arr[l] # only one element hence it is the min and max
    if n==2:
        return (arr[l+1], arr[l]) if arr[l+1]<=arr[l] else (arr[l], arr[l+1])
    
    mid = l+(r-l)//2
    
    mn_left, mx_left = tournament(arr, l, mid)
    mn_right, mx_right = tournament(arr, mid+1, r)
    # 2 comp
    mn = min(mn_left, mn_right)
    mx = max(mx_left, mx_right)
    return mn,mx
    #
# Method: Pair comp
# If n is odd then min and max of 1st element (0 comp) + min and max of n-1 elements (even) pair wise comp
# If i is even then min and max of 1st 2 elements (1 comp) + remaining n-2 elements (even)
# 3n/-2 comparisons if power of 2 else more than that
def pair(arr):
    if len(arr)&1: # odd take 1st element as min and max
        mn, mx =  arr[0], arr[0]
        i = 1
    else: # atleast 2 elements
        mn,mx = (arr[1], arr[0]) if arr[1]<=arr[0] else (arr[0], arr[1])
        i = 2 # start from 2
    
    while i < len(arr) - 1:
        # Simplification:
        j, k = (i,i+1) if arr[i] < arr[i+1] else (i+1, i)
        mn = min(mn, arr[j])
        mx = max(mx, arr[k])
        i+=1
        # if arr[i] < arr[i+1]:
        #     # compare current element with min and next with max
        #     curr_mn = arr[i]
        #     curr_mx = arr[i+1]
        # else:
        #     # compare current element with max and next with min
        #     curr_mn = arr[i+1]
        #     curr_mx = arr[i]
            
        # mn = min(mn, curr_mn)
        # mx = max(mx, curr_mx)
        # i+=1
        
    return mn,mx

    
arr= [6,9,0,3,2,0,1]
print(basic(arr))
print(tournament(arr, 0, len(arr)-1))
print(pair(arr))
            
        
    