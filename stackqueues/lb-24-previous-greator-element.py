# apply next-greatest element from opposite side of array.
def prev_greatest_element(arr):
    n = len(arr)
    mds = []
    ans = [0]*n
    for i, val in enumerate(arr[::-1]):
        if len(mds)==0 or val < arr[mds[-1]]:
            mds.append(n-i-1)
        else:
            while len(mds) and val > arr[mds[-1]]:
                ans[mds.pop()] = val
            mds.append(n-i-1)

    while len(mds):
        ans[mds.pop()] = -1
    return ans




arr = [10, 4, 2, 20, 40, 12, 30]
# -1, 10, 4, -1, -1, 40, 40
print(prev_greatest_element(arr))