# Given a tree find if all leaf are at same level or not

import copy

def height(root):
    if not root:
        return 0
    return 1 + max(height(root.left), height(root.right))


def at_same_level(root, ht):
    if not root:
        return True 
    if root.left == None and root.right==None:
        return ht==1
    left = at_same_level(root.left, ht-1)
    right = at_same_level(root.right, ht-1)
    return left and right

# without calculating height
ht = None
def at_same_level2(root, curr_ht):
    if not root:
        return True 
        
    if root.left == None and root.right==None:
        nonlocal ht
        if not ht:
            ht = curr_ht
        return ht==curr_ht
    
    left = at_same_level2(root.left, curr_ht+1)
    # if you found false the return don;t go for right
        
    right = at_same_level2(root.right, curr_ht+1)
    
    return left and right

# call at_same_level2(root, 0)
    