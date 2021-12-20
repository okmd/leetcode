# given 2n+2 numbers where 2n are pairwase same, 2 numbers are different.
# aabbcdefef
# find the non-repeating -> cd
def method1(nums):
    hashing = {k:0 for k in set(nums)}
    for i in nums:
        hashing[i]+=1
    # reurn only with count 1
    return [i[0] for i in filter(lambda x: x[1] == 1, hashing.items())]

def method2(nums):
    # idea is to xor all the numbers then result will be xor = c^d
    # to extract one of the element eith c or d, use xor property.
    # as it is known as x ^ x will only be 0. hence two unique number c and d will not give you 0.
    # hence, the result is non-zero, hence atleat one bit is set in the xor result.
    # that set bit will be from either c, or d but not both as we have took xor and result is non-zero.
    # seperate into two parts based on the set bit, so c will fall in one set and d will fall into other set.
    # by xoring the set will all xor result the values of c and d can be achieved.
    # help -> https://www.youtube.com/watch?v=u5-ss5kKy7g&ab_channel=RachitJain

    # Take the xor of all the elements
    xor = 0
    for num in nums:
        xor ^= num
    # now distribute into two sets based on the kth set bit, xor can never be 0, so atleast one of the bit will be 1
    # 1st set bit from the LSB
    set_bit = xor & -xor
    # if that bit is not set then and will give 0 (set0) else set1
    set1 = 0
    for num in nums:
        if num&set_bit: # kth bit is set.
            set1 ^= num # add to set1 and xor
    # calculate first number from set1 as it contains the one number in set1 and other in set0.
    a = set1^xor
    b = a^xor
    # again taking the with xor it will give you one of the number.
    # return sorted
    return [a,b] if a<b else [b,a]


nums  = [1,2,3,2,1,4]
print(method1(nums))
print(method2(nums))