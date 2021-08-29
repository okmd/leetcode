#NOTE: Application of Monotonically Decreasing Sequence
#   SIMILAR PROBLEMS:
#   1. Stock price 1&2 - LC
#   2. Carfleet 1&2 - LC
#   3. Maintain previous greator elements/ next greator elements.

# you are give prices of a stock for different days.
# need to find the span of ith day price.
# span of ith day pirce = in how many previous days this price was high among all previous prices < current prices.
# Step 1: for starting day its price itself is considered hence = 1
# Step 2: if reach LHS out of bound then index+1
# step 3: else index-previous high index = span
def find_span(arr):
    mds = []  # monotonically decreasing price of stock
    span = []  # span of each day
    for i, v in enumerate(arr):
        # if mds is i.e 1st element there is no previous high hence it will have only 1 span
        # or if current element is less tha prevous price then also span will be 1, just itself.
        if len(mds) == 0 or arr[mds[-1]] > v:
            span.append(1)
        else:
            # when the current price is more than previous then find till which day my price is high
            # just remove the mds value to get previous high price.
            while len(mds) and arr[mds[-1]] < v:
                mds.pop()
            # if no element left for high price > v it is the highest as of now and index+1 is its span
            if len(mds) == 0:
                span.append(i+1)
            # otherwise current index-previous high index is the span of current element
            else:
                span.append(i-mds[-1])
        # every time add the index of current elment in mds, order is maintained
        # if empty just add, if value less than previous one just add
        # if value more then all the elements are removed less than current value hence mds order is maintained.
        mds.append(i)

    print(mds)
    print(span)


if __name__ == "__main__":
    prices = [40, 50, 20, 60, 10, 30, 50, 30, 10, 90, 120, 3]
    find_span(prices)
