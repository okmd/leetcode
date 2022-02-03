# Given root of tree
# find the right mirror of the tree

# but some time you may asked to not change the structure.
def right_mirror(root):
    not root:
        return 
    temp = root.left
    root.left = root.right
    root.right = temp
    right_mirror(root.left)
    right_mirror(root.right)
    
    
# Create a new tree instead of changing it
def right_mirror(root):
    if not root:
        return None
    # create new node with same value as curr root node
    mirror = Node(root.data)
    # make right child from left child of original tree by mirroing
    mirror.right = right_mirror(root.left)
    # same for left child
    mirror.left = right_mirror(root.right)
    # return root of new mirror tree
    return mirror
    
    