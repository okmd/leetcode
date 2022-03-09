# monotonically increasing stack is a stack which stack contains all the values in increasing order from bottom to top.
def get_mis(arr):
    mis = []
    for i in arr:
        if len(mis)==0:
            mis.append(i)
        elif mis[-1]<i:
            mis.append(i)
        else:
            temp = []
            while len(mis) and mis[-1]>i:
                temp.append(mis.pop())
            mis.append(i)
            while len(temp):
                mis.append(temp.pop())
    return mis



# monotonically decreasing stack is a stack which stack contains all the values in decreasing order from bottom to top.
def get_mds(arr):
    mis = []
    for i in arr:
        if len(mis)==0:
            mis.append(i)
        elif mis[-1]>i:
            mis.append(i)
        else:
            temp = []
            while len(mis) and mis[-1]<i:
                temp.append(mis.pop())
            mis.append(i)
            while len(temp):
                mis.append(temp.pop())
    return mis

if __name__=="__main__":
    print(get_mis([4,5,2,0,3]))
    print(get_mds([4,5,2,0,3]))