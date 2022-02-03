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