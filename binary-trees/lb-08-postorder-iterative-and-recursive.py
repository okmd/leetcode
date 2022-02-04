# Given a root of binary tree find the post-order traversal of bt
def Rpostorder(root):
    if not root:
        return
    Rpostorder(root.left)
    Rpostorder(root.right)
    print(root.data, end=" ")
    
            
            
def Ipostrder(root):
    if not root:
        return 
    stackin = [root]
    stackout = []
    while stackin:
        curr = stackin.pop()
        # it will be usefull only after visiting all the left and right node ans
        # i.e using stack and reverse of stack will give actual ans
        stackout.append(curr.data)
        
        if curr.left:
            stackin.append(curr.left)
            
        if curr.right:
            stackin.append(curr.right)
    
    # Reverse of stack is postorder        
    while stackout:
        print(stackout.pop(), end=" ")
        
        
# Keep going left till none
# right -> again keep going left
# if reached end i.e no left no right put it in ans
# come back and put it in answer.
def Ipostorder2(root):
    if not root:
        return
    pos = []
    stack = []
    curr = root
    while stack or curr:
        if curr:
            # 1st time visit, add to stack and keep going left
            stack.append(curr)
            curr = curr.left
        else:
            # found none, left end
            # find right
            temp = stack[-1].right
            # if right not none
            if temp:
                # keep going right->left*->right etc
                curr = temp
            else:
                # if it is none i.e last node, pop and take it ans and
                temp = stack.pop()
                pos.append(temp.data)
                # going back as the element exists in the stack
                # if current element if the right child of previous i.e top of the stack
                # i.e you came through that element
                while stack and temp==stack[-1].right:
                    #remove that element and add to ans as no further visiting required for it
                    temp = stack.pop()
                    pos.append(temp.data)
    return pos