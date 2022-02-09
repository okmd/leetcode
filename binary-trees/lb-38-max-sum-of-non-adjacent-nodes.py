# Given a binary tree find max sum with non-adjacent nodes
# https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
        
def max_sum(root):
    if not root:
        return 0
    # without_including_root
    without_including_root = max_sum_dp(root.left) + max_sum_dp(root.right)
    #with_including_root
    with_including_root = root.data
    if root.left:
        with_including_root += max_sum_dp(root.left.left)
        with_including_root += max_sum_dp(root.left.right)
    if root.right:
        with_including_root += max_sum_dp(root.right.left)
        with_including_root += max_sum_dp(root.right.right)
    
    return max(with_including_root, without_including_root)
    
    
# DP memoization can also be appleied to reduce time complexity
dp = {}
def max_sum_dp(root):
    if not root:
        return 0
    if dp.get(root, None):
        return dp[root]
    # without_including_root
    without_including_root = max_sum_dp(root.left) + max_sum_dp(root.right)
    #with_including_root
    with_including_root = root.data
    if root.left:
        with_including_root += max_sum_dp(root.left.left)
        with_including_root += max_sum_dp(root.left.right)
    if root.right:
        with_including_root += max_sum_dp(root.right.left)
        with_including_root += max_sum_dp(root.right.right)
    
    dp[root] =  max(with_including_root, without_including_root)
    return dp[root]
    
        
        
    
        