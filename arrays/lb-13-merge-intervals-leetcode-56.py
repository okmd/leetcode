# you are given some set of intervals as [starti, endi]
# merge overlapping intervals where endi >= starti+1

def merge_intervals(intervals):
    # sort the inrerval according to starting time.
    intervals = sorted(intervals, key=lambda interval: interval[0])
    i = 0
    ans = []
    while i < len(intervals):
        # take to advance i but not entered into the loop, or merge not found for this interval.
        merge = False
        temp_interval = intervals[i]
        while i < len(intervals) and temp_interval[1] >= intervals[i][0]:
            # check and set the max using both interval end, as they are merged
            # we have sorted according to interval start time but not interval end time.
            temp_interval[1] = max(temp_interval[1], intervals[i][1])
            i+=1
            merge = True
        # append the ans either merged or unique interval.
        ans.append(temp_interval)
        # if while loop increased it then don;t otherwise increase i to get next interval.
        if not merge:
            i += 1
    
    return ans


# intervals = [[1,3],[2,5],[2,6],[8,10],[15,18]]
# intervals = [[1,4],[0,4]]
intervals = [[1,4],[2,3]]
print(merge_intervals(intervals))