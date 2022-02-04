## Pre/In/Post order in single call O(n) space and time
def pre_in_post(root):
    if not root:
        return
    pre = []
    ino = []
    pos = []
    stack = [(root, 1)]
    
    while stack:
        top, visited = stack[-1]
        if visited==1:
            pre.append(top.data)
            stack.pop()
            stack.append((top, 2))
            # keep on visiting left
            if top.left:
                stack.append((top.left, 1))
                
        elif visited==2:
            ino.append(top.data)
            stack.pop()
            stack.append((top, 3))
            # keep on visiting left, right
            if top.right:
                stack.append((top.right, 1))
        else:
            # going back so remove the element.
            pos.append(top.data)
            stack.pop()
            
    print(pre)
    print(ino)
    print(pos)
            