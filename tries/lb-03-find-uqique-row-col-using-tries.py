from collections import OrderedDict

def row_col(row, col, matrix):
    t = Trie()
    m = OrderedDict()
    for r in range(0, row*col, col):
        sr = "".join(matrix[r:r+col])
        t.insert(sr)
        m[sr]=True
        
    return list(m.keys())