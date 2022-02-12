# Predecessor -> 1 left + extreme right
# Successor   -> 1 right + extreme left
# while going left maintain succ for leaf and only one child node.
# while going right maintain pred for ...

def pred(root):
    # 1 left + extreme right
    root = root.left
    while root and root.right:
        root = right.right
    return root


def succ(root):
    # 1 right + extreme left
    root = root.right
    while root and root.left:
        root = right.left
    return root


# in range pred and succ
def pred_succ_in_range(root, key):
    if not root:
        return
    if root.key == key:
        if root.left:
            pre = pred(root)
        if root.right:
            suc = succ(root)
        return
    elif root.key > key:
        # lies in left
        suc = root
        pred_succ_in_range(root.left, key)
    else:
        # lies in right
        pred = root
        pred_succ_in_range(root.right, key)
