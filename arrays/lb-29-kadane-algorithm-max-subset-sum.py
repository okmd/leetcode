# Kdane algorithm is used to find maximum subset sum in o(n).
# at starting max_ending_here[meh] = max_so_far[msf] = arr[0]
# at any point max_ending_here = max(arr[i], max_ending_here + arr[i])
# update the max_so_far, if got another maximum.

def max_subset_sum(arr):
    meh = msf = arr[0]
    for i in range(1, len(arr)):
        meh = max(arr[i], meh + arr[i])
        msf = max(meh, msf)
    return msf

def optimization(arr):
    for i in range(1, len(arr)):
        arr[i] += arr[i-1] if arr[i-1]>0 else 0
    return max(arr)


print(max_subset_sum([-2, -3, 4, -1, -2, 1, 5, -3]))
print(optimization([-2, -3, 4, -1, -2, 1, 5, -3]))
