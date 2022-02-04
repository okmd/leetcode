# Given a root of tree find print in order traversal of binary tree
from collections import deque
from turtle import st

from numpy import cumsum


def Rinorder(root):
    if not root:
        return
    Rinorder(root.left)
    print(root.data, end=" ")
    Rinorder(root.right)
    
    
def Iinorder(root):
    if not root:
        return
    curr = root
    # stack for storing the recursion calls,
    # in recursive approach it is taken care by default
    stack = []
    while stack or curr:# till there is any node in stack or pointed by curr
        # till we reach end
        if curr:
            stack.append(curr)
            curr = curr.left 
        else:
            # now left is visited, pop elment as it is not required anymore
            curr = stack.pop()
            # print after coming from left
            print(curr.data, end=" ")
            # visit right of current node
            curr = curr.right
            
            