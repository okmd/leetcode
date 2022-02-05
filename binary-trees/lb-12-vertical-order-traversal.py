# You are give root of binary tree you job is to print the vertical order using Q and dictionay, and heap
# print from left ro right, leaft HD to most HD. HD of root is 0

from queue import Queue
# accepted by GFG
def vertical_order(root):
    if not root:
        return
    q = Queue()
    q.put((root, 0))
    visited = {} # <key, heapq>

    mn,mx = 0, 0

    while q.qsize():
        curr, hd = q.get()
        if not visited.get(hd, None):
            visited[hd] = []
        # to maintain sorted order
        visited[hd].append(curr.data)

        if curr.left:
            q.put((curr.left, hd-1))
            mn = min(mn,hd-1)
            
        if curr.right:
            q.put((curr.right, hd+1))
            mx = max(mx, hd+1)

    ans = []
    # to avoid sorting of nlogn find the min and max HD
    for i in range(mn, mx+1):
        for ele in visited[i]:
            ans.append(ele)
    return ans
    
        
        
# this code is accepted by GFG but not LC     
#[3,1,4,0,2,2] =>[[0],[1],[3,2,2],[4]]
#[1,2,3,4,6,5,7] = >[[4],[2],[1,5,6],[3],[7]]