# https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
# time complexity is n/2 i.e O(n)
def iterative(lst):
    i, j = 0, len(lst)-1
    while i < j:
        lst[i], lst[j] = lst[j], lst[i]
        i += 1
        j -= 1
    
def recursive(lst, start, end):
    if start > end:
        return
    recursive(lst, start+1, end-1)
    lst[start], lst[end] = lst[end], lst[start]
    

lst = [1, 2, 3, 7]
print(lst)
iterative(lst)
print(lst)
recursive(lst, 0, len(lst)-1)
print(lst)
print(lst[::-1]) # I don;t know where to start and stop but take step of 1 from the end.