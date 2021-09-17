from tree import BinaryTree

# Idea is to travese the tree and find parent of each node in some datastructure.
# Now start from the target node.
# visit at distance 0->1-> .. k
# maintain a visited array so that do not repeate.
# 


def find_parents(root):
    # O(n)
    parents = {root.val: None}
    def helper(root):
        if not root:
            return
        if root.left:
            parents[root.left.val] = root
        if root.right:
            parents[root.right.val] = root
        
        helper(root.left)
        helper(root.right)
    helper(root)
    return parents
    



def kth(root, target, k):
    # do bfs from target node
    # go to left, right and parent node only if not null and not visisted
    q = [target]
    ans = []
    visited = set()
    parents = find_parents(root)
    while len(q):
        n = len(q)
        for _ in range(n):
            curr = q.pop()
            visited.add(curr.val)
            if k==0:
                ans.append(curr.val)
                continue
            if curr.left and curr.left.val not in visited:
                q.insert(0, curr.left)

            if curr.right and curr.right.val not in visited:
                q.insert(0, curr.right)

            if parents[curr.val] and parents[curr.val].val not in visited:
                q.insert(0, parents[curr.val])
        k-=1
    return ans

    





if __name__ == "__main__":
    target = 5
    k = 4
    arr = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]
    t = BinaryTree()
    t.build(arr)
    ans = kth(t.root, t.search(target), k)
    print(ans)