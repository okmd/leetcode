# Given 2 array of values and weight
# some capacity W
# get max value by placing the item of weight w in bag of Capacity W
# as is fractional knapsack so be greedy


def fractional_knapsack(val, wt, W):
    n = len(val)
    # sort the item by profit or value
    arr = [(v,w) for v , w in zip(val, wt)]
    arr.sort(key=lambda x:x[0]/x[1], reverse=True) # max profit per unit of wt should come first.
    prof = 0
    for i in range(n):
        if arr[i][1] <= W:
            prof += arr[i][0]
            W -= arr[i][1]
        else:
            # value per unit of weight
            ratio = arr[i][0]/arr[i][1]
            prof += ratio*W
            break # should not continue as capacity is full
            
    return int(prof)

val = [60,100,120]
wt = [10,20,30]
W = 50
print(fractional_knapsack(val, wt, W))
            
            
            