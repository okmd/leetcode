#Given an array print inoder of tree

def inorder(arr):
    def __helper(i):
        if i>=len(arr) or arr[i]==None:
            return
        __helper(2*i+1)
        print(arr[i], end=" ")
        __helper(2*i+2)
    
    __helper(0)

def parent(arr, i):
    if i==0:
        return -1
    if not i&1:
        return arr[i//2-1]
    return arr[i//2]

arr = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]
inorder(arr)
print()
print(parent(arr, 5))