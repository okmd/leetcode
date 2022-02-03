# Given root of tree find the diameter of the tree
# diameter is end-node to end-node distance
# It may or may not pass through root


# WIll give TLE
# as height is calculated each time height = O(logn)
# for each node i.e nlogn and furter calling of diameter on left and right = n^2logn
def diameter(root):
    if not root:
        return 0
    # diameter passing through root
    d_root = height(root.left) + height(root.right) + 1
    # diameter passing through left child
    d_left = diameter(root.left)
    # diameter passing through right child
    d_right = diameter(root.right)
    # maximum of all is the diameter of tree
    return max(d_root, d_left, d_right)


# store height of each node i.e skewed tree.
dp = {}
def height(root):
    if not root:
        return 0
    if dp.get(root, None):
        return dp[root]
    dp[root] =  1 + max(height(root.left), height(root.right))
    return dp[root]

def reduce_time(root):
    return diameter(root)
    
    
# using heights at each node
def helperDiam(root):
    # if it none then 0 height and 0 diameter
    if not root:
        return [0, 0]
    # find diameter of left child
    left = helperDiam(root.left)
    # find diameter of right child
    right = helperDiam(root.right)
    # height of root
    height_till_now = max(left[0], right[0]) + 1 # left height + right height + 1
    # diameter oof tree
    diameter_till_now = max(left[0] + right[0]+1, max(left[1], right[1])) # NOTE: LEETCODE do not consider node for diameter calculation hence remove +1
    # left height+right height, max of diameter of left child and right child
    
    return [height_till_now, diameter_till_now]