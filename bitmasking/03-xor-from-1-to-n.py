# xor of all the elements from 1 to N
def xor_of_n(n):
    if n%4==0:
        return n
    elif n%4==1:
        return 1
    elif n%4==2:
        return n+1
    elif n%4==3:
        return 0
    # this is just the observvation not any algorithm
    # as it is observed that xoring from 1 to n follows this property.


if __name__=="__main__":
    print(xor_of_n(20))
    print(xor_of_n(2))
    print(xor_of_n(5))