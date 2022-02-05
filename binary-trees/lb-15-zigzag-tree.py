# Given root of binary tree print
# the zigzag level order,
# root(left-right), r->l, l->r ..

from quque import Queue
# accepted in LC but gfg gives TLE
def zigzag(root):
    if not root:
        return
    Q = Queue()
    Q.put(root)
    ans = []
    even_level = False
    # Do same as level order but change reverse the ans alternatevely
    while Q.qsize():
        # ans per level
        level  = []
        for i in range(Q.qsize()):
            curr = Q.get()
            level.append(curr.data)
            if curr.left:
                Q.put(curr.left)
            if curr.right:
                Q.put(curr.right)
        # reverse the ans
        if even_level:
            ans.append(level[::-1])
        else:
            ans.append(level)
        # alternate level for direction to push answer
        even_level = not even_level
    return ans

