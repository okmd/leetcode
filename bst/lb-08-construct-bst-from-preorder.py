# https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
# Method 1: O(n^2) for each element start from root and place at its location
def method1(preorder):
    def helper(root, val):
        if not root:
            return Node(val)
        if val < root.data:
            root.left = helper(root.left, val)
        elif val > root.data:
            root.right = helper(root.right, val)
        return root

    root = None
    for i, val in enumerate(preorder):
        root = helper(root, val)


# Method 2: O(nlong) inorder of bst will be sorted so sort preorder and make binary
# tree which will be unique and BST (nlogn) + O(n)
def method2(pre):
    ino = sorted(pre)  # O(nlogn)
    n = len(ino)
    print(pre, ino)
    # construct tree from inouder and preorder
    mapping = {k: i for i, k in enumerate(ino)}  # O(n) space

    def helper(pre, ino, i, j, k, l):
        if j < i or l < k:
            return None
        root = Node(pre[i])
        in_idx = mapping[pre[i]]
        elements_left = in_idx - k
        root.left = helper(pre, ino, i+1, i+elements_left, k, in_idx-1)
        root.right = helper(pre, ino, i+elements_left+1, j, in_idx+1, l)
        return root
    # pre start-end, ino start-end
    return helper(pre, ino, 0, n-1, 0, n-1)


# Methdo 3: O(n) As the preorder is like ROOT|LEFT|RIGHT so all all elements are in this order only,
# so create root then left subtree then right subtree
# instead of starting from root start from current node as the elements will be like ROOT|LEFT|RIGHT

def method3(pre):
    # points to the next element when a node is created
    i = 0

    def helper(pre, maxx):
        nonlocal i
        if i == len(pre):
            return None
        if pre[i] > maxx:
            return None
        root = TreeNode(pre[i])
        i += 1
        root.left = helper(pre, root.val)
        root.right = helper(pre, maxx)
        return root
    return helper(pre, 100000)
