# Given a tree and 2 nodes find min distance between them

# Method 1: traverse for both elements from root ans respective paths till node found
# start from left to right till element missmatch, last matching element is LCA.

# Method 2:
def lca(root, a, b):
    # assuming a and b exists in tree and all nodes have unique values
    def helper(root, a, b):
        if not root:
            return False
        
        # special case: when one node is decendent of other then 
        # 1st occuring will be lca
        if root.data in [a,b]:
            return root

        lstatus = helper(root.left, a, b)
        rstatus = helper(root.right, a, b)

        if lstatus and rstatus:
            return root

        return lstatus if lstatus else rstatus

    return helper(root, a, b)
# same solution can be extended to 
# if both found return node
# if only one found then find other below this node i.e will not exits anywhere else
# if found the return current node else -1