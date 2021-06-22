# Given a set and you need to find all the subset of given set.
# every element have two choices to be present or not present.
# so total possible combination will be 0 to 2^n-1 i.e 2^n elements in the subset.
# each binary number from 0 to 2^n-1 represent a subset with setbits.
# 2^n-1 == 1<<n-1

def find_subsets(elements):
    n = len(elements)
    subsets = []
    for mask in range(0, 1<<n):
        subset = []
        for j in range(0, n):
            if(mask & 1<<j):
                subset.append(elements[j])
        subsets.append("".join(subset))
    return subsets


# printing the code
elements = "ABC"
subsets = find_subsets(elements)
for i,subset in enumerate(subsets):
    print(f"{i+1}. {subset}")