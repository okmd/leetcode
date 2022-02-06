from collections import defaultdict
 
class Graph():
 
    def __init__(self, V):
        self.V = V # list of vertices
        self.graph  = defaultdict(list)
 
    def addEdge(self, v, w):
        # Add w to v ist.
        self.graph[v].append(w)
        # Add v to w list.
        self.graph[w].append(v)
        
    def dfs(self, visited, key):
            if not visited[key]:
                visited[key] = True
                for nei in self.graph[key]:
                    self.dfs(visited, nei)
        
    def connected(self):
        visited = {k:False for k in self.V}
        # call dfs one time, it should visit all if connected
        self.dfs(visited, self.V[0])
        # check if anyone is unvisited
        return all(visited.values())
    
    def _cyclic_helper(self, curr, parent, visited):
        visited[curr] = True
        for nei in self.graph[curr]:
            # print(curr, nei, parent, visited)
            if not visited[nei]:
                if self._cyclic_helper(nei, curr, visited):
                    return True
            elif parent!=nei:
                return True
        return False
            
        
    
    def cyclic(self):
        # It will check cycles for both connect and not connect graph
        # if a node is visited then its parent should not be same.
        # if same then not cyclic else cyclic
        # in undirected graph if you get and visited node in the path then it must contain cyclic
        visited = {k:False for k in self.V}
        for node in self.V:
            if not visited[node]:
                if self._cyclic_helper(node, -1, visited):
                    return True 
        return False
    
    def is_tree(self):
        # if forest 
        if not self.connected():
            return False
        
        # if forest 
        if self.cyclic():
            return False
        
        return True
        
        
        
g2 = Graph([1,2,3,4,5])
g2.addEdge(1, 2)
g2.addEdge(2, 3)
# g2.addEdge(3, 4)
# g2.addEdge(1, 5)
# g2.addEdge(5 ,3)

print(g2.connected())
print(g2.cyclic())
print(g2.is_tree())
