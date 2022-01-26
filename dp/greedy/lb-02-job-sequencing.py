# given the n jobs and their deadline and profits
# you need to maximize the profit by selecting the job.
# job must be completed within deadline.

# Brute force 
# generate all subsets of Jobs, then find the profit for each job then find max of profit.
# this is exponential

# Method 1: Greedy about the profit
# sort the jobs based on profit
# create and deadline array with max(dealines) size
# pick to job with max profit and place at the its deadline in deadline array.
# repeate the same process for other jobs.
# if cell is occupied then place in earlier cell.
#O(n^2)
def greedy_sequence(arr):
    n = len(arr)
    # sort based on profit in decending order
    arr.sort(key=lambda x:x[2], reverse=True)
    # create deadline array of max deadline size
    deadline = [False]*max(map(lambda x:x[1], arr))
    profit = []
    for i in range(n):
        job, deadl, prof = arr[i]
        while deadl:
            if not deadline[deadl-1]:
                deadline[deadl-1] = job
                profit.append(prof)
                break
            deadl -= 1
        
    # print(deadline) 
    # print(profit)   
    return len(profit), sum(profit)

# Optimization using heap :O(nlogn)
import heapq
def optimization(arr):
    # sort the array by deadline try to place large deadline first
    # if more than one job has same deadline then it will only place the job with max profit using heap if slots are available
    n = len(arr)
    arr.sort(key=lambda x:x[1], reverse=True)
    # print(arr)
    maxheap = []
    profit = []
    for i in range(n):
        job, deadl, prof = arr[i]
        free_slots = deadl if i==n-1 else deadl - arr[i+1][1]
        heapq.heappush(maxheap, (-prof, deadl, job)) 
        # 1st argument is treated to create min(+default) or maxheap(-)
        while free_slots and maxheap:
            prof, deadl, job = heapq.heappop(maxheap)
            # print(job, deadl, prof)
            profit.append(-prof)
            free_slots -= 1
        # while loop will one run 1 time for different deadlines, but may work multiple time is jobs have same deadline.
             
    return len(profit), sum(profit)
    
    
arr = [(1,4,20), (2,1,10), (3,1,40), (4,1,30)]#[(1,2,100), (2,1,19), (3,2,27), (4,1,25), (5,1,15)]
print(greedy_sequence(arr))
print(optimization(arr))