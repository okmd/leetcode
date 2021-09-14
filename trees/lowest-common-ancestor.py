from tree import BinaryTree
# Idea is to return NULL except if value is found
# if there is one NULL in left or then take non null value
# if both are non null then it is the lca
# if both values are present into the same subtree then top will be the lca.


def lca(root, p, q):
    if not root or root.val == p.val or root.val == q.val:
        return root
    print(root.val, end="->")

    left = lca(root.left, p, q)
    right = lca(root.right, p, q)

    if left and right:
        # one element is in left side and other is no right side.
        return root
    elif left:
        # element is left
        return left
    else:
        # not in left then either right or both none
        return right


t = BinaryTree()
t.build([3, 5, 1, 6, 2, 0, 8, None, None, 7, 4])
p = t.search(5)
q = t.search(4)
lca_node = lca(t.root, p, q)
print(f"LCA: {lca_node.val}")
