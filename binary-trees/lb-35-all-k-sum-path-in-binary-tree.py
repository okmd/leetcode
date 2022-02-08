# Given a binary tree and required path sum k
# print all the downwards path from any node to anyother node with sum k
# Idea is to reach to the leaf node and save path then find the path from that node using cached path

def all_paths(root, k):
    paths = []
    def helper(root, k):
        if not root:
            return 
        # append current element in the paths
        paths.append(root.data)
        # call left till you reach end
        helper(root.left, k)
        # call right 
        helper(root.right, k)
        # now find the path with sum k
        sm = 0
        n = len(paths)
        for i, ele in enumerate(paths[::-1]):
            sm += ele 
            if sm == k:
                print(paths[n-i-1:])
            # do not break as by adding some +ve and -ve values the sum can again become k
        # remove the current element from path
        # in the above level current element is not required to find path till there
        paths.pop()
    # call the function to print all the paths
    helper(root, k)