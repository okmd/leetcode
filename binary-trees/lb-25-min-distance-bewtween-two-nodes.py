# Given a tree and 2 nodes find min distance between them


def LCA(root, a, b):
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

    
def min_distance(root, a, b):
    lca = LCA(root, a, b)
    
    def find(root, a, depth):
        if not root:
            return 0
        if root.data == a:
            return depth
        left = find(root.left, a, depth+1)
        right = find(root.right, a, depth+1)

        # it is guranteed that node is exits then no need to check
        # find a and b
        return left if left else right
    
    return find(lca, a, 0) + find(lca, b, 0)
