# height of binary tree max depth that we can reach
# 1+max(hight of left, height of right) subtree
def height(root):
    if not root:
        return 0
    return 1 + max(height(root.left), height(root.right))
