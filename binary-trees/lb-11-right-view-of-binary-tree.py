# Given tree with root
# find the right view of tree i.e last node in each level
# start visiting right to left insead of left to right

visited = [False]*1000 # height of tree
def recursive(root, level):
    if not root:
        return 
    if not visited[level]:
        print(root.data)
        visited[level] = True 
    
    # instread of calling from left call to right first
    recursive(root.right, level+1)
    recursive(root.left, level+1)
    
    
    
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
            
        if curr.left:
            stack.append((curr.left, level+1))
        # insert at last, it will be top of the stack
        # right one should be 1st for this case.  
        if curr.right:
            stack.append((curr.right, level+1))
        
        
        
        