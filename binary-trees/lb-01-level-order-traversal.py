# Given a root of tree find level order traversal
def levelOrder(root):
        if not root:
            return
        Q = [root]
        ans = []
        while len(Q):
            root = Q.pop()
            ans.append(root.data)
            if root.left:
                Q.insert(0, root.left)
            if root.right:
                Q.insert(0, root.right)
        return ans
    
from queue import Queue 
def levelOrder2(root):
    if not root:
        return
    Q = Queue()
    Q.put(root)
    ans = []
    while Q.qsize():
        level  = []
        for i in range(Q.qsize()):
            curr = Q.get()
            level.append(curr.data)
            if curr.left:
                Q.put(curr.left)
            if curr.right:
                Q.put(curr.right)
        ans.append(level)
    return ans
                
    