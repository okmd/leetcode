
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

    def search(self, val):
        def helper(root, val):
            if not root:
                return -1
            if root.data == val:
                return root
            elif root.data < val:
                return helper(root.right, val)
            return helper(root.left, val)

        return helper(self.root,  val)


nodes = [4, 2, 7, 1, 3]
search = 8
bst = BST()
for ele in nodes:
    bst.insert(ele)
found = bst.search(search)
print(found.data == search if found != -1 else False)
