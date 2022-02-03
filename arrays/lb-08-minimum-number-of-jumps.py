# Given n elements
# each no represents the steps ahead
def canReachEnd(arr):
    n = len(arr)
    max_reachable_index = 0
    for i in range(n):
        # if i is more than maximum reachable index then you can never reach end.
        if max_reachable_index < i:
            return False 
        # find max reachable index from here, or if already from previous element
        max_reachable_index = max(max_reachable_index, i + arr[i])
        
    # if not return from the loop then loop ends i.e reached to end
    return True

def minJumps(arr):
    n = len(arr)
    if n==0 or arr[0]==0:
        return -1
    dp = [float('inf')]*n
    dp[0] = 0
    # at each point find the min jumps required to reach at j from i
    for i in range(n):
        for j in range(i+1, min(i+arr[i]+1, n)):
            dp[j] = min(1+ dp[i], dp[j]) # already has min jumps or 1+min jups from ith index.
    
    # return the last element as it will store the min jumps to reach end
    return -1 if dp[-1]==float('inf') else dp[-1]

arr = [2, 3, 1, 1, 2, 4, 2, 0,  1, 1]#[1,1,3,0,6,7]#
print(canReachEnd(arr))
print(minJumps(arr))

# NOTE: TLE only 138/141 testcase pass