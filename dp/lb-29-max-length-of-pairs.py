
# (a,b) (c, d) pair = b<c and a<b and c<d
def maximum_length_pairs(arr):
    # sort based on the second values
    arr.sort(key=lambda x: x[1])
    curr, ans = float('-inf'), 0
    for st, ed in arr:
        if curr < st:
            curr = ed
            ans += 1
    return ans


arr = [(5,  24), (39, 60), (15, 28), (27, 40), (50, 90)]
print(maximum_length_pairs(arr))
