# You are given source and destination houses.
# and Pipes between them with weight
# job is to minimize the weight of pipe (capacity)

def dfs_helper(adj, node, min_cost):
    # if this is the last node i.e house where tap is to be installed
    if adj.get(node, None) == None:
        return node, min_cost
    # traverse to all the neighbours
    for neighbour, cost in adj[node]:
        # find min cost and return at the end
        min_cost = min(min_cost, cost)
        return dfs_helper(adj, neighbour, min_cost)

def dfs(adj):
    ans = []
    #nodes with indegree 0
    indegree = set()
    for a in adj:
        indegree.add(adj[a][0][0])
    zero_indegree =  adj.keys() - indegree
    # start only from where indegree is zero that can create multiple component
    for a in zero_indegree: 
        min_cost = 10000 # large cost
        b ,c = dfs_helper(adj, a, min_cost)
        ans.append((a, b, c))# append ans as first node, last node and minimum cost
        
    return ans


def water_connection(source, destination, diameter):
    adj = {}
    # create adjacency list
    for so, de, di in zip(source, destination, diameter):
        if not adj.get(so, None):
            adj[so] = []
        adj[so].append((de, di))
    return dfs(adj)
    
a = [7,5,4,2,9,3]
b = [4,9,6,8,7,1]
d = [98,72,10,22,17,66]

print(water_connection(a,b,d)) #[(2, 8, 22), (3, 1, 66), (5, 6, 10)]