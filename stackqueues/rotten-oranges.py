# Given set of rotten oranges, fresh oranges and empty holes in 2d array space.
# Only adjacent fresh oranges cas be rott.
# if all fresh oranges can't be rott then  return -1
# adjacent are only up, down, left and right.
class Node:
    def __init__(self, c, x, y) -> None:
        self.cost = c
        self.x = x
        self.y = y


class Queue:
    def __init__(self) -> None:
        self.values = []

    def size(self):
        return len(self.values)

    def empty(self):
        return self.size() == 0

    def enqueue(self, val):
        self.values.append(val)

    def dequeue(self):
        if self.empty():
            return -1
        val = self.values[0]
        del self.values[0]
        return val

def print_matrix(mat):
    r = len(mat)
    c = len(mat[0])
    for i in range(r):
        for j in range(c):
            print(mat[i][j], end=" ")
        print()

def check_dims(rows, cols, x, y):
    if 0 <= x < rows and 0 <= y < cols:
        return True
    return False


def rott(Q, node, matrix):
    cost, x, y = node.cost, node.x, node.y
    rows = len(matrix)
    cols = len(matrix[0])
    cost += 1
    # top
    if check_dims(rows, cols, x-1, y) and matrix[x-1][y] == 1:
        Q.enqueue(Node(cost, x-1, y))
        matrix[x-1][y] += 1
    # down
    if check_dims(rows, cols, x+1, y) and matrix[x+1][y] == 1:
        Q.enqueue(Node(cost, x+1, y))
        matrix[x+1][y] += 1
    # left
    if check_dims(rows, cols, x, y-1) and matrix[x][y-1] == 1:
        Q.enqueue(Node(cost, x, y-1))
        matrix[x][y-1] += 1
    # right
    if check_dims(rows, cols, x, y+1) and matrix[x][y+1] == 1:
        Q.enqueue(Node(cost, x, y+1))
        matrix[x][y+1] += 1


def rotten_oranges(matrix, debug=True):
    cost = 0
    Q = Queue()
    rows = len(matrix)
    cols = len(matrix[0])
    # Pick each rotten orange
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 2:
                Q.enqueue(Node(0, i, j))
    # rott all adjacent orange
    while not Q.empty():
        node = Q.dequeue()
        cost = node.cost
        rott(Q, node, matrix)
    # final matrix
    if debug:
        print_matrix(matrix)
    # check for any fresh orange

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 1:
                return -1
    
    return cost


if __name__ == "__main__":
    matrix = [[2, 1, 0, 2], [1, 0, 1, 0], [1, 0, 0, 1]]
    matrix1 = [[2, 1, 0, 2], [1, 0, 1, 2], [1, 0, 0, 1]]
    for mat in [matrix, matrix1]:
        cost = rotten_oranges(mat)
        if cost == -1:
            print("No, Na bhai, abhi acche hai kuch.")
        else:
            print(f"Yes, Sab kuch sada diya {cost} unit cost.")
