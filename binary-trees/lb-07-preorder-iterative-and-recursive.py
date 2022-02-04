# Given a root of binary tree find the pre-order traversal of bt

def Rpreorder(root):
    if not root:
        return
    print(root.data, end=" ")
    Rpreorder(root.left)
    Rpreorder(root.right)
    
    
    
def Ipreorder(root):
    if not root:
        return
    curr = root
    # stack for storing the recursion calls,
    # in recursive approach it is taken care by default
    stack = []
    while stack or curr:# till there is any node in stack or pointed by curr
        # till we reach end
        if curr:
            # print 1st visit
            print(curr.data, end=" ")
            stack.append(curr)
            curr = curr.left 
        else:
            # now left is visited, pop elment as it is not required anymore
            curr = stack.pop()
            # visit right of current node
            curr = curr.right
            
            
            
            
def Ipreorder2(root):
    if not root:
        return
    stack = [root]
    while stack:
        curr = stack.pop()
        print(curr.data, end=" ")
    
        if curr.right:
            stack.append(curr.right)
        # top of the stack, choose next  
        if curr.left:
            stack.append(curr.left)
        # it is guranteed that left will be called first before right if exits.
            
            
            
