def merge(intervals):
    # sort all the intervals based on the start time
    intervals = sorted(intervals, key=lambda interval: interval[0])
    i = 0
    ans = []
    # for each interval
    while i < len(intervals):
        merge = False
        # current interval can be merged or not
        temp_interval = intervals[i]
        # merge only if overlapping i.e pre end time >= current start time
        while i < len(intervals) and temp_interval[1] >= intervals[i][0]:
            temp_interval[1] = max(temp_interval[1], intervals[i][1])
            i += 1
            merge = True

        ans.append(temp_interval)
        # move the the last non merged one if merged=True
        if not merge:
            i += 1

    return ans
