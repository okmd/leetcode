# Given the root of tree
# find the longest path and its sum

def max_sum_path(root):
    max_height = 0
    max_sum = 0
    def helper(root, ht, curr_sum):
        nonlocal max_height, max_sum
        if not root:
            return 0
            
        curr_sum += root.data  
        
        if root.left == None and root.right == None:
            if ht >= max_height:
                max_height = ht
                max_sum = curr_sum
            return
                
            
        helper(root.left, ht+1, curr_sum)
        helper(root.right, ht+1, curr_sum)
    
    helper(root, 0, 0)
    return max_sum
    