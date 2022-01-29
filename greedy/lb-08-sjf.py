# Clear
    
import heapq 

def sjf(arr, n):
    # zip to sort in one go
    arr = [(i, j, k) for i, j, k in zip(arr[0], arr[1], arr[2])] # process, arrival, bt
    # sort based on bt then at then pid
    arr.sort(key=lambda x:(x[1], x[2], x[0]))
    # add first element to min heap
    min_heap = [(arr[0][2],arr[0][1], arr[0][0])]
    # use this time to track the execution
    curr_time =0
    i=1
    ans =[]
    # while heap has some unfinished process
    while min_heap:
        bt, at, p = heapq.heappop(min_heap)
        # current process finshed i.e completion time
        curr_time += bt
        ans.append([p, at, bt, curr_time])
        # till now add all the process having arrival time till curr_time.
        # if process not arrived till now:
        if i<n and arr[i][1]>curr_time:
            # increase till the next job comes # remember jobs are sorted by AT
            curr_time += (arr[i][1]-bt)
            
        while i<n and arr[i][1]<=curr_time:# put till this time @arrived
            # add all the process such that min bt process will be at time @min heap
            heapq.heappush(min_heap, (arr[i][2], arr[i][1], arr[i][0]))
            # do noly till all the process come
            i+=1
        
    return ans


# RUN: CODE
n = 4
arr = [[i+1 for i in range(n+1)], # Process
    [2,0,4,5], # arrival time
    [3,4,2,4], # burst time
    ]

ans = sjf(arr, n)
print(f"Process\tAT\tBT\tCT\tTAT\tWT")
for i in range(n):
    tat = ans[i][3] - ans[i][1]
    wt  = tat - ans[i][2]
    print(f"P{ans[i][0]}\t{ans[i][1]}\t{ans[i][2]}\t{ans[i][3]}\t{tat}\t{wt}")
