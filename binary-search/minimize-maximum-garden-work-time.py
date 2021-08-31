# You are given N garden and K workers N >= K.
# You have some constraints as
# - A garden can have only one worker.
# - A worker can work in adjacent garden only.
# Your goal is to minimize the maximum time to complete all the work of garden.

# Approach 1:
# divide the array into k parts and calcualte all the working time per worker and find max time.
# arrange those k-1 pipes into N-1 position to get all the possible division and find time.
# finally get the min of all the maximum time.

# Approach 2:
# use binary search as low = max(times), high = sum(times), mid= is the time to check
# is is possible to divide the work such that work gets completed.
# if yes then it the maximum time, if it less than any previous time then it is minimum till now.
def possible_to_work(works, time, k):
    # O(n)
    sm = 0
    workers = 1
    for w in works:
        sm += w
        if sm > time:
            workers += 1
            sm = w
    return workers <= k

def minimize_max_work_time(works, k):
    # O(logn) - O(n)
    low = max(works)
    high = sum(works)
    ans = 10**9
    while low <= high:
        mid = low + (high-low)//2
        if possible_to_work(works, mid, k):
            ans = min(ans, mid)
            high -= 1
        else:
            low = mid+1

    return ans


# O(nlogn) - O(n^2)
works = [5, 8, 2, 10, 11, 12]
k = 3
minimum_max_work_time = minimize_max_work_time(works, k)
print(f"Minimum max-work time: {minimum_max_work_time}")