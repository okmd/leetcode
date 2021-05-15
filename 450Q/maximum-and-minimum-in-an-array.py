# https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
'''
There are three methods of finding the min and max of given array.
Method 1: Simple linear serial search.
    -> create a pair to find min and max.
    -> for one element, both are min and max. 
    -> for 2 element find min and max of it.
    -> for more than 2 elements, compare it with min, or max.
'''
def simple_linear_search(lst):
    n = len(lst)
    if n==1:
        mn, mx = lst[0]
    else:
        mn = min(lst[0], lst[1])
        mx = max(lst[0], lst[1])
    
    for i in range(2, n):
        if lst[i] > mx:
            mx = lst[i]
        elif lst[i] < mn:
            mn = lst[i]
    return mn, mx

lst = [1,5,6,3,9,0,3]
print(simple_linear_search(lst))

'''
Method 2:
    Tournament Method
        -> for single element both are min and max
        -> for two elements find min and max
        -> for more than 2 elements recursively find min and max in left and right half of the array,
        -> finally find min and max of all the arrays.
'''
def tournament_method(lst):
    if len(lst)==1:
        return (lst[0], lst[0])
    elif len(lst)==2:
        return (min(lst[0], lst[1]), max(lst[0], lst[1]))
    lh_min, lh_max = tournament_method(lst[:len(lst)//2])
    rh_min, rh_max = tournament_method(lst[len(lst)//2:])
    return (min(lh_min, rh_min), max(lh_max, rh_max))
                
                

lst = [1,5,6,3,9,0,3]
print(tournament_method(lst))
                
                
'''
Method 3:
    Pair method 
    -> start each pair and place min in one box, max in other box.
    -> finally make the min and max in box.
'''

def pair_method(lst):
    if len(lst)==1:
        return (lst[0], lst[0])
    mn, mx = min(lst[0], lst[1]), max(lst[0], lst[1])
    for i in range(2, len(lst)-1, 2):
        mn = min(mn, min(lst[i], lst[i+1]))
        mx = max(mn, max(lst[i], lst[i+1]))
        
    return (mn, mx)
    
lst = [1,5,6,3,9,0,3]
print(pair_method(lst))
    
    
            