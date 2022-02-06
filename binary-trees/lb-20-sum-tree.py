
# check if it is sum tree or not
def sum_tree(root):
    if not root:
        return True, 0
    
    if root.left == None and root.right==None:
        return True, root.data
    # check if left tree is sum tree or not
    lstatus, lvalue = sum_tree(root.left)
    # check if right tree is sum tree or not
    rstatus, rvalue = sum_tree(root.right)
    
    sm = (lvalue+rvalue)
    # check if root node tree is sum tree or not
    # only if both left and right are subree and sum is equal to data
    status = lstatus and rstatus and root.data == sm
    # return current status and sum of current data and child sum as sum till now
    return status, sm + root.data