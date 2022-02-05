# Given root of binary tree find the bottom view of the bt
## Using the idea of vertical order traversal i.e HD@root = 0, left +1, right -1 or vice versa
        
# Accepted by GFG        
from queue import Queue

def bottomview(root):
    if not root:
        return
    q = Queue()
    q.put((root, 0))
    visited = {} # <key, heapq>

    mn,mx = 0, 0

    while q.qsize():
        curr, hd = q.get()
        # only maintain last occurance, so repalce
        visited[hd] = curr.data

        if curr.left:
            q.put((curr.left, hd-1))
            mn = min(mn,hd-1)
            
        if curr.right:
            q.put((curr.right, hd+1))
            mx = max(mx, hd+1)

    ans = []
    # to avoid sorting of nlogn find the min and max HD
    for i in range(mn, mx+1):
        ans.append(visited[i]) 
    return ans