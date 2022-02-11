# Idea is to take min while going forward
# if sm contribute +ve then ignore it as we dont want to maximize

def min_cont_subarray(arr):
    min_till_now = arr[0]
    sm_till_now = arr[0]
    for ele in arr[1:]:
        if min_till_now > 0:
            min_till_now = ele
        else:
            min_till_now += ele
        min_till_now = min(min_till_now, sm_till_now)
    return min_till_now