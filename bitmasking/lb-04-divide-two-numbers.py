## NOTE: divide without using *, / and %

def method1(dividend, divisor):
    # - sign is 1's complement + 1 = ~a+1
    # divisor*quotient <= dividend, quotient is power of 2 
    # find the sign of answer based on the sign of dividend and divisor
    sign = (dividend<0)^(divisor<0)
    # make +ve both the values
    dividend = abs(dividend)
    divisor = abs(divisor)
    # loop while the divisor is less than dividend
    # answer variable
    ans = 0
    while divisor <= dividend:
        quotient = 1
        temp = divisor
        # divisor*2^q < dividend
        while temp <= dividend:
            temp <<= 1      # multiply by 2
            quotient <<= 1  # multiply by 2
        # divide by 2 and add to ans
        ans += quotient>>1
        # divide by 2 and decrease from dividend
        dividend -= temp>>1
    # return considering sign
    return ~ans+1 if sign else ans

# 27/3 = 3*2^3 => 3/3 => 3*2^0 => 2^3 + 2^0
print(method1(27,3))
print(method1(28,3))
print(method1(28,-3))