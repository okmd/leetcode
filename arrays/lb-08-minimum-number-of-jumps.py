# Given n elements
# each no represents the steps ahead
from array import array


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
    if n==0:
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

# NOTE: TLE only 138/141 testcase pass GFG
# LeetCode accepted @https://leetcode.com/problems/jump-game-ii


int minJumps(int arr[], int n) {
        int max_reachable_index = arr[0];
        int can_move = arr[0]; // can move x steps before hitting next jump
        int jumps = 1; 
        if (n == 1) return 0;        // if only one element in arr then no jums are reauired// took one jump from starting point
        if (arr[0] == 0) return -1;  // can;t move from 1st element
               // if only one element in arr then no jums are reauired
        for (int i = 1; i < n; i++) {
            if (i > max_reachable_index) return -1;
            if (i == n - 1) return jumps;  // as reached the end of array hence return the jums taken.
            max_reachable_index = max(max_reachable_index, i + arr[i]);
            // took one step
            can_move--;
            if (can_move == 0) {
                jumps++;
                can_move = max_reachable_index - i;
                // how many steps_required to reach the point where 
                // next jump will be taken
            }
        }
    }