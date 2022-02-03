# Given a root of tree find level order traversal
def height(root):
    if not root:
        return 0
    return 1 + max(height(root.left), height(root.right))

def reverseLevelOrder(root):
    if not root:
        return
    h = height(root)
    ans = []
    
    def helper(root, level):
        if not root:
            return
        if level==1:
            ans.append(root.data)
        helper(root.left, level-1)
        helper(root.right, level-1)
    
    for i in range(h,0,-1):
        helper(root, i)
        
    return ans