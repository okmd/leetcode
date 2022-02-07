# Given arrays of inorder and preorder of binary tree
# construct the unique tree
# Idea is to pick root from preorder and find index in inorder.
# divide till that index left subtree and beyond that index as right subtree
# by taking that number of elements after root in preorder for both left and right.

def construct_tree(pre, ino):
    ino_map = {k: i for i, k in enumerate(ino)}

    def helper(preorder, inorder, pstart, pend, istart, iend):
        if pstart > pend or istart > iend:
            return None

        # find root from preorder
        root_data = preorder[pstart]
        root_idx_in_inorder = ino_map[root_data]
        elements_in_left_tree = root_idx_in_inorder - istart
        # create root node
        root = Node(root_data)
        # assign left and right child
        root.left = helper(preorder, inorder, pstart+1, pstart + elements_in_left_tree, istart, root_idx_in_inorder-1)
        root.right = helper(preorder, inorder, pstart + elements_in_left_tree+1, pend, root_idx_in_inorder+1, iend)
        # return the root of newly created node.
        return root

    return helper(pre, ino, 0, len(pre)-1, 0, len(ino)-1)
