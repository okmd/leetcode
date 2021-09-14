class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def height(self):
        def __helper(root):
            if not root:
                return 0
            if root.left == None and root.right==None:
                return 1
            return 1 + max(__helper(root.left), __helper(root.right))
        
        return __helper(self.root)


    def build(self, arr):
        def __helper(i):
            if i >= len(arr) or arr[i] == None:
                return None
            root = TreeNode(arr[i])
            root.left = __helper(2*i+1)
            root.right = __helper(2*i+2)
            return root

        self.root = __helper(0)

    def inorder(self):
        def __helper(root):
            if not root:
                return
            __helper(root.left)
            print(root.val, end=" ")
            __helper(root.right)

        __helper(self.root)

    def search(self, val):
        def __helper(root):
            if not root:
                return
            if root.val == val:
                return root
            left =  __helper(root.left)
            right = __helper(root.right)
            if left:
                return left
            if right:
                return right

        return __helper(self.root)
        


if __name__=="__main__":
    arr = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]
    t = BinaryTree()
    t.build(arr)
    t.inorder()
    print(t.search(9).val)
