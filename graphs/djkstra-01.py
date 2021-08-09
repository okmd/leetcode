import heapq
        
class Graph:
    def __init__(self, nodes):
        self.adj = {k:[] for k in nodes}
        self.dist = {k:float('inf') for k in nodes}
        
    def insert(self, edges):
        for u,v,c in edges:
            self.adj[u].append((v,c))
            
    def single_source(self, source, dest):
        self.dist[source] = 0
        pq = [(source, 0)]
        while len(pq):
            curr, curr_dist = heapq.heappop(pq)

            for v,c in self.adj[curr]:
                if curr_dist + c < self.dist[v]:
                    self.dist[v] = curr_dist + c
                    heapq.heappush(pq, (v, curr_dist + c))
                    
        return self.dist[dest]
            
            
    
if __name__=="__main__":
    g = Graph(['a','b','c','d', 'e'])
    edges = [('a','b', 3), ('a','e', 5),('b','c', 6),
             ('b','e', 2),('c','d', 2),('d','c', 7),
             ('d','a', 3),('e','c', 4),('e','d', 6),('e','b', 1)]
    g.insert(edges)
    s ='a'
    d = 'd'
    print(f"Shortest path from {s} to {d} is {g.single_source(s, d)}.")
            
    