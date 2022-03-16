// Method 1:
// find in-pre-post order traversals O(n)
// now create heap O(n)
// same as max-heapify but find min instead of max
https://github.com/okmd/leetcode/blob/main/heap/lb-19-convert-min-heap-to-max-heap.cpp

// Method 2: this may not work if BST is not CBT
// find inorder traversals
// traverse in the inorder and replce the element
// this will make the tree as heap