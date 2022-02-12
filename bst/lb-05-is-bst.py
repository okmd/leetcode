# This method will not work when subtree is bst but left child is > root
# eg. 3 2 5 1 4
def not_working(root):
    if not root or root.left == None and root.right == None:
        return True
    if not root.left:
        return not_working(root.right) and root.right.data > root.data
    if not root.right:
        return not_working(root.left) and root.left.data < root.data

    return not_working(root.left) and not_working(root.right) and root.left.data < root.data < root.right.data


# So all the left child elements should be < root and
# all the right child elements should be > root.
def bst(root, mn, mx):
    def helper(root, mn, mx):
        if not root:
            return True
        # only need to check if root lies in between min and max
        return mn <= root.data <= mx and helper(root.left, mn, root.data-1) and helper(root.right, root.data+1, mx)
    return helper(root, -100005, +100005)
