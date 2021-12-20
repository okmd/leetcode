def count_set_bits(n):
    # intialize to count from 0
    c=0
    # while number does not become 0
    while n:
        # if last bit is set
        if n&1:
            c+=1
        # divide by 2 to make new last bit 1001 => 100
        n>>=1
        
    return c

print(count_set_bits(5))