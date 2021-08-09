def graph(nodes, edges):
    # create adjacency list for nodes
    g = [[] for _ in range(nodes)]
    # create edges between the nodes or add edges
    for edge in edges:
        g[edge[0]].append(edge[1])
        g[edge[1]].append(edge[0])
        
    return g

def dfs(g, visited, pos):
    visited[pos] = True
    print(pos, end=" ")
    for i in g[pos]:
        if visited[i]==False:
            dfs(g, visited, i)

def bfs(g, visited, pos):
    visited[pos] = True
    Q = [pos]
    while len(Q):
        curr = Q.pop()
        print(curr, end=" ")
        for i in g[curr]:
            if visited[i]==False:
                Q.insert(0, i)
                visited[i] = True
                
        
        
    

if __name__=="__main__":
    nodes = 4
    g = graph(nodes, [(0,1),(0,2),(0,3),(1,3),(2,3)]) 
    dfs(g, [False]*nodes, 0)
    print()
    bfs(g, [False]*nodes, 0)