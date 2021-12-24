# Given two numbers x and y.
# Two numbers 1<=l<=r<=32 starting from LSB.
# set the set bit of y in x. x=1010, y=1101 then new y=1110.

def method1(x,y,l,r):
    if l<1 or r>32:
        return y
    # idea is to set each bit from l to r
    for i in range(l,r+1):
        # non-zero, denotes the set bit position at i where it has to be made 1 in y.
        # zero, y's bit is 0 at position i l
        mask = (1<<(i-1))&y
        if mask:
            x |= mask
    return x

def method2(x,y,l,r):
    if l<1 or r>32:
        return y
    # create the mask of 1s of reuired length
    ml = r-l+1
    mask = (1<<ml) - 1 # if 2 bits has to be set between l and r then mask = 11
    # shift mask to required position
    mask = mask<<(l-1)
    # extract only the bits of y in the mask range
    mask = mask&y
    # set the bit in the x
    x |= mask
    return x



x=10
y=13
l=2
r=3
print(method1(x,y,l,r))
print(method2(x,y,l,r))