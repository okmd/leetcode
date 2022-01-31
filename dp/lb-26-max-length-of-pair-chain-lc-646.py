# Given n pairs of element.
# two pair p1(a,b), p2(c,d) form chain if b<c
# find the max chain length

# using lis technique O(n^2)
from ast import operator


def max_chain_len(arr):
    # sort the array based on right value
    n = len(arr)
    arr.sort(key=lambda x:x[1])
    dp = [1]*n # represents the longest increasing subsequence till ith index.
    # initally each element is in lis iteself hence 1 for each element.
    i= 1
    while i<n:
        j=0
        while j<i:
            if arr[i][0] > arr[j][1]:
                # this element is included  in chain and previous till j we have already calculated the chain length
                # so new chain length till i is dp[i]
                dp[i] = max(dp[i], 1 + dp[j])
            j += 1
        i+=1
    return max(dp)# max element will be the chain length for complete array
    
# optimization over time: O(nlong)
def optimization(arr):
    arr.sort(key=lambda x:x[1])
    curr, ans = float('-inf'), 0
    for st, ed in arr:
        if curr<st:
            curr = ed 
            ans+=1
    return ans
# as the chain will always be in the form of 
# a<b<c<d ... 
     
 
    
# RUN: CODE DP with GRID  
print(max_chain_len([[1,2],[3,4],[2,3]])) #2
print(max_chain_len([[7,9],[4,5],[7,9],[-7,-1],[0,10],[3,10],[3,6],[2,3]])) # 4
print(optimization([[1,2],[3,4],[2,3]])) #2
print(optimization([[7,9],[4,5],[7,9],[-7,-1],[0,10],[3,10],[3,6],[2,3]])) # 4