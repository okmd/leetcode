#Given root of binary tree find the boundary traversal of tree

def boundary(root):
    if not root:
        return 
    ans = []
    def isleaf(root):
        return root.left==None and root.right==None
        
    def left(root):
        if not root or isleaf(root):
            return
        # if leaf then stop
        ans.append(root.data)
        if root.left:
            left(root.left)
        else:
            left(root.right)
            
            
    def leaf_inorder(root):
        if not root:
            return
        if isleaf(root):
            ans.append(root.data)
            return
        leaf_inorder(root.left)
        leaf_inorder(root.right)
        
    stack = []  
    def right(root):
        if not root  or (root.left==None and root.right==None):
            return 
        stack.append(root.data)
        if root.right:
            right(root.right)
        else:
            right(root.left)
        
    
    # insert root data
    ans.append(root.data)
    # if it is the only root then return
    if isleaf(root):
        return ans
    # call left for leftboundary
    left(root.left)
    # call inorder tree for leaves
    leaf_inorder(root)
    # find right boundary
    right(root.right)
    
    # pop from stack and put in ans
    # insert reverse of right boundary from bottom to top
    while stack:
        ans.append(stack.pop())
    
    return ans