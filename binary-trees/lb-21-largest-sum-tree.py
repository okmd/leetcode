
import sys
# check if it is sum tree or not
def sum_tree(root):
    if not root:
        return 0
    
    # check if left tree is sum tree or not
    lvalue = sum_tree(root.left)
    # check if right tree is sum tree or not
    rvalue = sum_tree(root.right)
    
    return max((lvalue+rvalue + root.data), -sys.maxsize)