from tree import BinaryTree

# Idea is to maintain the max throughout the path.


def good_nodes(root):
    total = 0

    def helper(root, mx):
        nonlocal total
        if not root:
            return
        if root.val >= mx:
            total += 1
            mx = root.val
        helper(root.left, mx)
        helper(root.right, mx)
    helper(root, root.val)
    return total


if __name__ == "__main__":
    arr = [3, 1, 4, 3, None, 1, 5]
    t = BinaryTree()
    t.build(arr)
    ans = good_nodes(t.root)
    print(ans)
