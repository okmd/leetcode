# Given the tree and convert it into the DLL
# inplace
def convert_to_dll(root):
    prev = Node(-1)
    head = prev
    def helper(root):
        nonlocal prev
        if not root:
            return 
        
        helper(root.left)
        root.left = prev
        prev.right = root
        prev = root
        helper(root.right)
        
    helper(root)
    # remove the dummy node and return head
    head.right.left = None
    head = head.right
    return head