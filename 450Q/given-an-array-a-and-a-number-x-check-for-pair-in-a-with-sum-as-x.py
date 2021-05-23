# Given an array and a sum x
# find two elements in the array whose sum is x.
# Method 1:

# Array must be sorted for this.
# works only for single pair of numbers.
def sortTwoPointer(arr, x):
    arr = sorted(arr)
    l = 0
    r = len(arr)-1
    all_pairs = []
    while l <= r:
        sm = arr[l]+arr[r]
        if sm == x:
            all_pairs.append((arr[l], arr[r]))
        if sm > x:
            r -= 1
        else:
            l += 1
    return all_pairs if len(all_pairs) else -1


arr = [4, 2, 0, 8, 14, 5, 1]
x = 16

res = sortTwoPointer(arr, x)

res = res if res != -1 else "not"
print(f"For given sum:{x} pair {res} exists.")
# Time complexity: O(nlogn) but will change if we use Quick sort, O(n^2)

# Method 2:
# Hashing: store in the set if complement is not present.
# Space and time O(n)


def hashsum(arr, x):
    required = set()
    all_pairs = []
    for i in arr:
        if x-i in required:
            all_pairs.append((i, x-i))
        else:
            required.add(i)
    return all_pairs


arr = [4, 2, 0, 8, 14, 5, 1]
x = 6
res = hashsum(arr, x)
res = res if res != -1 else "not"
print(f"For given sum:{x} pair {res} exists.")

# Method 3:
# Using remainders of elements less than x(sum).


def remSum(arr, x):
    rem = [0 for _ in range(x)]

    for i in range(len(arr)):
        if arr[i] < x:
            rem[arr[i] % x] += 1

    for i in range(1, x//2):
        if rem[i] and rem[x-i]:
            print("Yes")
            break

    if i >= x//2:
        if x % 2 == 0:
            if rem[x//2] > 1:
                print("Yes")
            else:
                print("No")
        else:
            if rem[x//2] and rem[x-x//2]:
                print("Yes")
            else:
                print("No")

arr = [4, 2, 0, 8, 14, 5, 1]
x = 6
remSum(arr, x)