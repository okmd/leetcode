def minVal(root):
    if not root:
        return -1
    while root.left:
        root = root.left
    return root.data
