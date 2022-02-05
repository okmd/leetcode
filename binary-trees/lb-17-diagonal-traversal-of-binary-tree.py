# given root of binary tree find the diagoanal view of tree
# idea is to change the horizontal distance in only one side i.e either left or right

def diagonal_traversal(root):
    visited = {}
    mx = 0
    def helper(root, hd):
        nonlocal mx
        if not root:
            return
        # if hd not found create a new list
        if not visited.get(hd, None):
            visited[hd] = []
        # append for this hd
        visited[hd].append(root.data)
        # max hd to print the ans
        mx = max(mx, hd)
        
        # insert left if exits
        if root.left:
            helper(root.left, hd+1)
        # insert right if exits
        if root.right:
            helper(root.right, hd) 
        
            
    helper(root, 0)
    ans = []
    for i in range(mx+1):
        for ele in visited[i]:
            ans.append(ele)
    return ans


# O(n) space and time complexity
    
            
        
    