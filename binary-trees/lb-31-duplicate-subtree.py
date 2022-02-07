# Given a binary tree and your job is to find if there exists duplicate subtree or not
# Use map to store the sub tree and count

def duplicate_binary_tree(root):
    # leaf node is not a size of two
    mapping = {}
    def helper(root):
        if not root:
            return " "
        # for leaf the size < 1 hence return as node not subree to cache
        if root.left == None and root.right==None:
            return "{}".format(root.data)
        
        # generate from left child and right child then join to make subtree
        left_subtree = helper(root.left)
        right_subtree = helper(root.right)
        
        # f string may not be supported in python3
        subtree =  "{} {} {}".format(left_subtree, root.data, right_subtree)
        if not mapping.get(subtree, None):
            mapping[subtree] = 0
        # cache in the map
        mapping[subtree] += 1
        # return subtree with this node
        return subtree
    # generate the maping cache of each subtree 
    helper(root)
    # get only duplicate subtree
    duplicates = [i for i in mapping.values() if i>1]
    # return 1 if exists else 0
    return 1 if len(duplicates) else 0