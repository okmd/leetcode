# Given 1-n numbers and in between numbers are missing and repeated
# find the count in O(n) and (1) time and space.

def brute_force(arr):
    count = {k+1:0 for k in range(len(arr))}
    for i in arr:
        if not count.get(i, None):
            count[i] = 0
        count[i]+=1        
    return count 

def freq(ele):
    return -ele if ele<=0 else 0

# (n) time and O(1) space inplace 
def space_optimized(arr):
    i = 0
    while i<len(arr):
        x = arr[i]-1
        # already counted, ignore and move next
        if arr[i]<=0:
            i+=1
        # occured 1 more time, just increase count and move ahead
        elif arr[x] <=0 :
            arr[x] -= 1
            i+=1
        # comming first time, store element to be replaced and mark freq=1 as represented -1
        else:
            arr[i] = arr[x]
            arr[x] = -1
    # make negative to +ve and non-negative to 0 as actual frequency       
    return list(map(freq, arr))


arr = [2,3,3,2,5]
print(brute_force(arr))
print(space_optimized(arr))