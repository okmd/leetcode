from tree import BinaryTree
# Idea is to get the max distance in left and right
# and add +1 for root


def height(root):
    if not root:
        return 0
    if root.left == None and root.right == None:
        return 1
    return 1 + max(height(root.left), height(root.right))


def diameter(root):
    if not root:
        return 0
    h1 = height(root.left)
    h2 = height(root.right)
    dl = diameter(root.left)
    dr = diameter(root.right)
    return max(h1+h2, max(dl, dr))


def optimizedDiameter(root):
    if not root:
        return [0, 0]
        
    left = optimizedDiameter(root.left)
    right = optimizedDiameter(root.right)
    height_till_now = max(left[0], right[0]) + 1
    diameter_till_now = max(left[0] + right[0], max(left[1], right[1]))
    return [height_till_now, diameter_till_now]


t = BinaryTree()
t.build([1, 2, 3, 4, 5])
print("Diameter: ", diameter(t.root))
print("Diameter: ", optimizedDiameter(t.root)[1])
