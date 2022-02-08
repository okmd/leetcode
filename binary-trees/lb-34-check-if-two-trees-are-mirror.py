# Given two trees are mirror of each other or not


# Binary tree
from collections import OrderedDict

def mirror(root1, root2):
    # both None
    if not (root1 or root2):
        return True 
    # only one is None
    if not (root1 and root2):
        return False 
    
    # if data not matching
    if root1.data != root2.data:
        return False 
    
    # call if both left and right child is also mirror
    return mirror(root1.left, root2.right) and mirror(root1.right, root2.left)

############## N-ary tree #############
class Node:
    def __init__(self, val):
        self.data = val 
        self.childrens = []
        
class NaryTree:
    def __init__(self, nodes, edges):
        self.nodes = OrderedDict() 
        
    def create(self, edges):
        for i in range(0, len(edges), 2):
            u,v = edges[i], edges[i+1]
            if not self.nodes.get(u, None):
                self.nodes[u] = Node(u)
            if not self.nodes.get(v, None):
                self.nodes[v] = Node(v)
            self.nodes[u].childrens.append(self.nodes[v])
            
        self.root =  self.nodes[list(self.nodes.keys())[0]]
        return self.root
    
    def show(self):
        def helper(root):
            if not root:
                return
            print(root.data, end=" ")
            for child in root.childrens:
                helper(child)
        helper(self.root)
        print(" ")
        
    def is_mirror(self, root2):
        stack = []
        def helper(root):
            if not root:
                return 
            stack.append(root)
            for child in root.childrens:
                helper(child)
                
        queue = []
        def helper2(root):
            if not root:
                return 
            for child in root.childrens:
                helper2(child)
            queue.insert(0, root)
            
        # fill stack and queue
        helper(self.root)
        helper2(root2)
        # from from stack and  queue and match
        count = max(len(stack), len(queue))
        while count:
            count -=1 
            if stack.pop().data != queue.pop().data:
                return False
        return True
            
                
            
            
                
        
    
n = 3
e = 2
edges1 = [1,2,1,3]
edges2 = [1,3,1,2]
nt = NaryTree(n, e)
root1 = nt.create(edges1)
nt2 = NaryTree(n, e)
root2 = nt2.create(edges2)
# print(root1.childrens)
nt.show()
nt2.show()
print(nt.is_mirror(root2))