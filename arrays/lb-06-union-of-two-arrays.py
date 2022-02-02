# Given two arrays of elements
# find union
# use  set data structure

def union(arr1, arr2):
    return set(arr1).union(arr2)

# O(n+m)log(n+m)
# dictionary has amortized search time of O(n)
def use_dict(arr1, arr2):
    count = {}
    for i in arr1:
        if not count.get(i, None):
            count[i] = 0
        count[i] += 1
    
    for i in arr2:
        if not count.get(i, None):
            count[i] = 0
        count[i] += 1
        
    
    return {i for i in count.keys()}


arr = [1,2,3,4,5]
arr1 = [1,2,3]

print(union(arr, arr1))
print(use_dict(arr, arr1))