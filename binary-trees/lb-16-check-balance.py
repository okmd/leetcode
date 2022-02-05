# checking if binray tree is balanced or not
# i.e absolute differece between the left and right subtree <=1

# as the height is caculated multiple time then store it
dp = {}# for all nodes
def height(root):
    if not root:
        return 0
    if dp.get(root, None):
        return dp[root]
    dp[root] = 1+ max(height(root.left), height(root.right))
    return dp[root]

def balance(root):
    if not root:
        return True
    return balance(root.left) and balance(root.right) and abs(height(root.left) - height(root.right)) <= 1
    
    
# a pair can also be used for each node to denote its height
def balance2(root):
    if not root:
        return True, 0
    left, lh = balance2(root.left)
    right, rh = balance2(root.right)
    return left and right and abs(lh-rh)<=1, 1 + max(lh, rh)