## NOTE: HARD gfg
# https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
# maximum of all subarray of size k
# given array, window size k
# Maximum of each subarray of size k
from collections import deque
def bruteforce(arr, k):
    # O(n**2)
    mxx = []
    for i in range(len(arr)-k+1):
        mx = -100
        for j in range(i, i+k):
            mx = max(mx, arr[j])
        mxx.append(mx)
    return mxx


def optimized(arr, k):
    # O(n)
    i, j = 0, 0
    dq = deque()
    mxx=[]
    while j < len(arr):
        # add to rear only element which are less than rear.
        # all greater elements will re removed till rear > arr[j]
        # due to this max element will always at front. all elements are in decreasing order.
        while len(dq) and dq[-1]<arr[j]:
            dq.pop()
        # add to the element
        dq.append(arr[j])
        # if window is not reached
        if j-i+1<k:
            j+=1
        # window is reached
        elif j-i+1==k:
            # find current windows result, as each window max element lies at 0th index of Q.
            mxx.append(dq[0])
            # dq has only elements are array which are usefull to calcualte max.
            # remove only if this element is used for calculation.
            # arr[i] is the initial value of window and will not be used any more.
            # dq[0] will only be removed if it the element which is going to be removed ie. arr[i]
            if dq[0]==arr[i]:
                dq.popleft()
            # slide the window right.
            i+=1
            j+=1
    return mxx


if __name__ == "__main__":
    arr = [[1,3,-1,-3,5,3,6,7],[4,1,3,2,6]]
    k = 3
    for i in arr:
        print(bruteforce(i, k))
        print(optimized(i, k))
