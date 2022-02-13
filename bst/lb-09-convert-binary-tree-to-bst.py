# You need to modify binary tree to bst without chaging the structure.
# Find inorder of binary tree
# Sort inorder
# traverse binary tree in inorder and place the values from sorted array.

def convert(root):
    inor = []

    def inorder(root):
        if not root:
            return
        inorder(root.left)
        inor.append(root.data)
        inorder(root.right)

    inorder(root)
    # sort
    sorted_inor = sorted(inor)
    # palce the value
    i = 0

    def place_inorder(root):
        nonlocal i
        if not root:
            return
        place_inorder(root.left)
        root.data = sorted_inor[i]
        i += 1
        place_inorder(root.right)

    place_inorder(root)
