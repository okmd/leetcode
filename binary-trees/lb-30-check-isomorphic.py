# Given two tree with roots
# find if they are isomorphic to each other
# isomorphic if child can be swapped at any level

def isomorphic(root1, root2):
    # if both none then true
    if not (root1 or root2):
        return True
    # it is about both trees not left and right child of same tree
    # if either of not none
    if not (root1 and root2):
        return False
    if root1.data != root2.data:
        return False
    # swapped  
    # ie. if left become right then right should become left and both should be isomorphic
    swapped = isomorphic(root1.right, root2.left) and  isomorphic(root1.left, root2.right)

    # not swapped
    # ie. if left is left then right sould be right and both should be isomorphic
    not_swapped = isomorphic(root1.left, root2.left) and  isomorphic(root1.right, root2.right)
    
    return swapped or not_swapped