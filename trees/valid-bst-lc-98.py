from tree import BinaryTree
import sys

# Note: if duplicate is not allowed then remove =
def valid_bst(root):
    def helper(root, left_min, right_max):
        if not root:
            return True
        if(left_min <= root.val and root.val <= right_max and helper(root.left, left_min, root.val) and helper(root.right, root.val, right_max)):
            return True
        return False
    return helper(root, -sys.maxsize, sys.maxsize)



if __name__ == "__main__":
    arr = [5, 4, 6, None, None, 3, 7]
    t = BinaryTree()
    t.build(arr)
    ans = valid_bst(t.root)
    print(ans)
