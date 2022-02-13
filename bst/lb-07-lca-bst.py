def LCA(root, a, b):
    if root.data > a and root.data > b:
        return LCA(root.left, a, b)
    elif root.data < a and root.data < b:
        return LCA(root.right, a, b)
    return root
