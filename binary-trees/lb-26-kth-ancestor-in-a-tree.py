# Given node and k find the kth ancestor if this node.

# O(n) time and space
def ancestor(root, k, key):
    path = []
    def helper(root, key):
        if not root:
            return False
        
        path.append(root.data)
        
        if root.data == key:
            return True
        
        if helper(root.left, key) or helper(root.right, key):
            return True
        
        path.pop()
        return False
    
    helper(root, node)
    n = len(path)-1
    return path[n-k] if n>=k else -1