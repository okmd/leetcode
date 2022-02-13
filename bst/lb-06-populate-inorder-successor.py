def populate(root):
    succ = None

    def helper(root):
        if not root:
            return
        helper(root.right)
        root.next = succ
        succ = root
        helper(root.left)
    helper(root)
