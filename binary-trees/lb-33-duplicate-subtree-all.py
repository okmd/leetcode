# Given a binary tree and your job is to find if there exists duplicate subtree or not
# Use map to store the sub tree and count

from collections import OrderedDict


def duplicate_binary_tree(root):
    # leaf node is not a size of two
    mapping = OrderedDict()

    def helper(root):
        if not root:
            return ""
        # # for leaf the size < 1 hence return as node not subree to cache
        # if root.left == None and root.right==None:
        #     return "{}".format(root.data)

        # generate from left child and right child then join to make subtree
        left_subtree = helper(root.left)
        right_subtree = helper(root.right)

        # f string may not be supported in python3
        subtree = "{} {} {}".format(left_subtree, root.data, right_subtree)
        if not mapping.get(subtree, None):
            mapping[subtree] = [0, None]
        # cache in the map
        mapping[subtree][0] += 1
        mapping[subtree][1] = root
        # return subtree with this node
        return subtree
    # generate the maping cache of each subtree
    helper(root)
    # get only duplicate subtree
    duplicates = [v[1] for _, v in mapping.items() if v[0] > 1]

    return duplicates
