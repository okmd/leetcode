# Given a binary tree your job is to change tree inplace
# node.value = left + right + curr

# Transform to sum tree
def sum_tree(root):
    if not root:
        return 0,0
    lcurr, lprev = sum_tree(root.left)
    rcurr, rprev = sum_tree(root.right)
    prev = root.data
    root.data = lcurr + lprev + rcurr + rprev
    return root.data, prev