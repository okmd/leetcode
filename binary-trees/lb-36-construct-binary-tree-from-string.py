# Given string of form root(left subtree)(right subtree)
# Job is to create the binary tree

# Idea is to break the problem into subproblem of same type i.e subtree
# solve the subtree string to binary tree and combine the tree.
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
def last_closing_bracket_of_leftsubtree(string, start, end):
    stack = []
    for i, ele in enumerate(string[start:end+1], int(start)):
        if ele == "(":
            stack.append("(")
        elif ele == ")":
            stack.pop()
            if not stack:
                return i 
    return None
        
# O(n^2)
def create_binary_tree(string, start, end):
    if start > end:
        return None # to create left and right child of Leaf node
    # first element of string is root.
    root = Node(string[start])
    # find the index of last ) of left subtree
    i = last_closing_bracket_of_leftsubtree(string, start, end)
    if i!=None:
        root.left = create_binary_tree(string, start+2, i-1) #  new subtree of form 2(2)(3)
        root.right = create_binary_tree(string, i+2, end-1) #  new subtree of form 2(2)(3)
        
        
    # return the root of newly created tree
    return root

def preorder(root):
    if not root:
        return
    print(root.data, end = " ")
    preorder(root.left)
    preorder(root.right)
    
    
s = "4(2(3)(1))(6(5))"
root = create_binary_tree(s, 0, len(s)-1)
preorder(root)