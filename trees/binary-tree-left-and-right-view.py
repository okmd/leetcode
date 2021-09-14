from tree import BinaryTree
# Idea is to maintain an visited array for each level
# first time lavel visit is the left view

def left_view(root, h):
    visited = [0]*h
    def __helper(root, l):
        if not root:
            return
        if not visited[l]:
            print(root.val, end=" ")
            visited[l] = 1
        # first left side visit to print left view
        __helper(root.left, l+1)
        # right side visit
        __helper(root.right, l+1)

    __helper(root, 0)


def right_view(root, h):
    visited = [0]*h
    def __helper(root, l):
        if not root:
            return
        if not visited[l]:
            print(root.val, end=" ")
            visited[l] = 1
        __helper(root.right, l+1)
        __helper(root.left, l+1)

    __helper(root, 0)

        
        




t = BinaryTree()
t.build([1,2,3,None,5,None,4])
print("Left: ", end=" ")
left_view(t.root, t.height())
print("\nRight: ", end=" ")
right_view(t.root, t.height())
