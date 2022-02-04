# Given tree with root
# find the left view of tree i.e 1st node in each level

visited = [False]*1000 # height of tree
def recursive(root, level):
    if not root:
        return 
    if not visited[level]:
        print(root.data)
        visited[level] = True 
    
    recursive(root.left, level+1)
    recursive(root.right, level+1)
    
    
    
def iterative(root):
    if not root:
        return
    stack = [(root,1)]
    visited = [False]*1000 # height of tree
    while stack:
        curr, level = stack.pop()
        if not visited[level]:
            print(curr.data)
            visited[level] = True 
            
        if curr.right:
            stack.append((curr.right, level+1))
        # insert at last, it will be top of the stack
        if curr.left:
            stack.append((curr.left, level+1))
        
        
        