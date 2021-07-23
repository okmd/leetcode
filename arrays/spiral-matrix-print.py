import unittest
# You are given a matrix of R x C size.
# You need to print the matrix from
# left to right along top,
# top to bottom along right,
# right to left along bottom,
# bottom to top alogn left
# and this repeats till matrix is printed completly.

matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9],
          [0, 4, 4]]
# output sould be: 1,2,3,6,9,4,4,0,7,4,5,8


def spiral_print(mat, r, c):
    # create 4 pointers to denote boundry
    top, left = 0, 0
    bottom, right = r-1, c-1
    output = []
    # direction denotes the direction to print the array
    # 0-> Top: left to right
    # 1-> Right: top to bottom
    # 2-> Bottom: right to left
    # 3-> Left: bottom to top
    direction = 0
    while left <= right and top <= bottom:
        if direction == 0:
            for i in range(left, right+1):
                output.append(mat[top][i])
            top += 1
        elif direction == 1:
            for i in range(top, bottom+1):
                output.append(mat[i][right])
            right -= 1
        elif direction == 2:
            for i in range(right, left-1, -1):
                output.append(mat[bottom][i])
            bottom -= 1
        elif direction == 3:
            for i in range(bottom, top-1, -1):
                output.append(mat[i][left])
            left += 1
        direction = (direction+1) % 4

    return " ".join(map(str, output))


class TestCode(unittest.TestCase):
    def setUp(self):
        pass
    
    def get_r_c(self, mat):
        if len(mat):
            return len(mat), len(mat[0])
        return 0, 0

    def test_spiral_non_uniform(self):
        matrix = [[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9],
                  [0, 4, 4]]
        r, c = self.get_r_c(matrix)
        self.assertEqual(spiral_print(matrix, r, c), "1 2 3 6 9 4 4 0 7 4 5 8")

    def test_spiral_uniform(self):
        matrix = [[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9]]
        r, c = self.get_r_c(matrix)
        self.assertEqual(spiral_print(matrix, r, c), "1 2 3 6 9 8 7 4 5")

    def test_spiral_row(self):
        matrix = [[1, 2, 3]]
        r, c = self.get_r_c(matrix)
        self.assertEqual(spiral_print(matrix, r, c), "1 2 3")

    def test_spiral_col(self):
        matrix = [[1],
                  [4],
                  [7]]
        r, c = self.get_r_c(matrix)
        self.assertEqual(spiral_print(matrix, r, c), "1 4 7")
        
    def test_spiral_empty(self):
        matrix = []
        r, c = self.get_r_c(matrix)
        self.assertEqual(spiral_print(matrix, r, c), "")
    


if __name__ == "__main__":
    unittest.main()
