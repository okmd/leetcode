
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, val):

        def helper(root, val):
            if not root:
                return Node(val)

            if root.data == val:
                return root

            elif root.data < val:
                root.right = helper(root.right, val)

            elif root.data > val:
                root.left = helper(root.left, val)

            return root

        self.root = helper(self.root, val)

    def inorder_successor(self, root):
        while root.left:
            root = root.left
        return root

    def delete(self, val):

        def helper(root, val):
            if not root:
                return
            if root.data > val:
                root.left = helper(root.left, val)
            elif root.data < val:
                root.right = helper(root.right, val)
            else:
                # if only leaf
                # if only one child
                if not root.right:
                    return root.left
                if not root.left:
                    return root.right
                # if has both child
                succ = self.inorder_successor(root.right)
                root.data = succ.data  # swap or overwrite
                # delete inorder successor
                root.right = helper(root.right, succ.data)
            return root
        return helper(self.root, val)

    def inorder(self):
        def helper(root):
            if not root:
                return
            helper(root.left)
            print(root.data, end=" ")
            helper(root.right)
        helper(self.root)
        print()


nodes = [4, 2, 7, 1, 3]
search = 4
bst = BST()
for ele in nodes:
    bst.insert(ele)
bst.inorder()
bst.delete(search)
bst.inorder()
