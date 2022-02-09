# Given the array of int root@i, left@2i, right@2i+1
# Convert to binary(assume) tree and
# find inorder and assign index
# sort by inorder value
# try to place the element at its index denoted by the index
# this operation will require min no of swaps

def inorder(arr):
    ans = []
    def helper(arr, i):
        if i>len(arr):
            return
        helper(arr, 2*i)
        ans.append(arr[i-1]) # array is 0-index based
        helper(arr, 2*i+1)
    helper(arr, 1)
    return ans

def minimum_swaps(arr):
    ino = inorder(arr)
    inorder_with_index = [(idx,val) for idx, val in enumerate(ino)]
    # sort by value
    inorder_with_index.sort(key=lambda x:x[1])
    # try to place all elements index to its location
    i = 0
    swaps = 0
    while i<len(inorder_with_index):
        curr_item = inorder_with_index[i]
        if curr_item[0] != i:
            swaps+=1
            inorder_with_index[i], inorder_with_index[curr_item[0]] = inorder_with_index[curr_item[0]], inorder_with_index[i] 
        else:
            i+=1
    return swaps
            
    
    
    
    
arr = [5, 6, 7, 8, 9, 10, 11]
print(minimum_swaps(arr))
    
    
# as we know that Inorder of BST is always sorted in ascending order
# so inorder of binary should also be sorted
# so to make it sorted take help of index
# intially inorder has sorted index
# then sort by values(become BST) but index changed its positions.
# now If we could change back index also to its original pos by swapping we can know the numbers of swaps required.