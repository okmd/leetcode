# Given arrays of inorder and postorder of binary tree
# construct the unique tree
# Idea is to pick root from postorder and find index in inorder.
# divide till that index left subtree and beyond that index as right subtree
# by taking that number of elements after root in postorder for both left and right.

def construct_tree(pos, ino):
    ino_map = {k: i for i, k in enumerate(ino)}

    def helper(postorder, inorder, pstart, pend, istart, iend):
        if pstart > pend or istart > iend:
            return None

        # find root from postorder
        root_data = postorder[pend]
        root_idx_in_inorder = ino_map[root_data]
        elements_in_left_tree = root_idx_in_inorder - istart
        # create root node
        root = Node(root_data)
        # assign left and right child
        root.left = helper(postorder, inorder, pstart, pstart + elements_in_left_tree-1, istart, root_idx_in_inorder-1)
        root.right = helper(postorder, inorder, pstart + elements_in_left_tree, pend-1, root_idx_in_inorder+1, iend)
        # return the root of newly created node.
        return root

    return helper(pos, ino, 0, len(pos)-1, 0, len(ino)-1)
