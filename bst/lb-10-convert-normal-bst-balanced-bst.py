# Balanced bst is the bst where height difference is atmost 1.
def find_inorder(root):
    arr = []

    def find(root):
        if not root:
            return
        find(root.left)
        arr.append(root.data)
        find(root.right)
    find(root)
    return arr


def convert_balanced_bst(root):
    # find the inorder traversal of tree.
    # divide in the middle of inorder traversals.
    # now create left, right child form sub tree.
    ino = find_inorder(root)
    # already bst
    # ino = sorted(ino) 

    def helper(arr, start, end):
        if start > end:
            return None
        mid = start + int((end-start)//2)
        root = Node(arr[mid])
        root.left = helper(arr, start, mid-1)
        root.right = helper(arr, mid+1, end)
        return root
    return helper(root, 0, len(ino)-1)
