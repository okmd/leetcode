# given string of n character
# each char has a frequency
# represent it in huffman tree and find the huffman code of each char.
# character having highest frequency will have least huffman code and vice versa.
# build max heap of frequency array.
# picking 2 element at a time from heap and create huffman tree.
import heapq

class Node:
    def __init__(self, f, c=None, l=None, r=None, t=True):
        self.frequency = f
        self.char = c
        self.left = l
        self.right = r
        self.terminal = t
        
    def __lt__(self, n):
        return self.frequency < n.frequency
    

def huffman_encoding(string, frequency):
    # create max heap of frequency
    max_heap = [Node(j, i) for i, j in zip(string, frequency)]
    heapq.heapify(max_heap)
    # print(max_heap)
    while len(max_heap)>1:
        # extract two nodes 1st min and second min
        left_node = heapq.heappop(max_heap)
        right_node = heapq.heappop(max_heap)
        # create new node and create pointers so that it can be traversed to print huffman-code
        new_node = Node(left_node.frequency+right_node.frequency)
        new_node.left = left_node
        new_node.right = right_node
        # mark it non terminal 
        new_node.terminal = False
        heapq.heappush(max_heap, new_node)
        
    # pre_order of tree root at max_heap
    def pre_order(root, ans):
        # whenever you reach to terminal then print the ans 
        if root.terminal:
            answer.append("".join(ans))
            return 
        # use backtracking to change the state of the ans
        ans.append('0')
        pre_order(root.left, ans)
        ans[-1] = '1' # pop 0 and then push 1 -> or simple replace with 1 top element
        pre_order(root.right, ans)
        ans.pop()
        
    # this will store all the ans 
    answer = []
    # pop from the heap and pass as root to for preorder traversal 
    pre_order(heapq.heappop(max_heap), [])
    return answer
         


string = "abcdef"
f = [5,9,12,13,16,45]
print(huffman_encoding(string, f))