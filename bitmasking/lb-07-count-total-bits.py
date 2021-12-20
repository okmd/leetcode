def bits(n):
    # Calculate the numbers of bits in the given number.
    # 100 =>3, 1010=>4, 111=>3
    c=0
    while n:
        c+=1
        n>>=1
    return c

def power_of_2(n):
    # check if number is in power of 2 i.e 1000(True) = 8, 101(False) = 5
    # power of 2 then 0
    return not n&(n-1)

def count_bits(n):
    # 0, and 1 will have same bits as numbers.
    if n<=1:
        return n
    nearest_power_2 = 1<<(bits(n)-1) # no of form 100 <= n
    ones_till_power2 = (nearest_power_2>>1)*(bits(n)-1) + 1 # total numbers of 1's upto nearest perfect binary number 2^x.
    # remaining numbers have 1 as MSB. and find the count of remaining from 1 to remaining_rows
    remaining_rows = n - nearest_power_2
    # return all the result 
    return ones_till_power2 + remaining_rows + count_bits(remaining_rows)

print(count_bits(4))
print(count_bits(10**8))