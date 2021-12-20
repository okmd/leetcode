def method1(n):
    # n+n+n .. n times
    # o(n)
    return sum(n for _ in range(n))

def method2(n):
    # even n^2 = (2n/2)^2 = 4x^2
    # odd n^2 = (2(n/2)+1)^2 = 4x^2 + 4x + 1 
    if n==1:
        return n
    if n&1:
        return 4*(method2(n//2) + n//2) + 1
    return 4*method2(n//2)

def method3(n):
    # using bitmasking
    # 15*15 = 15*(8+4+2+1) => split into power of two.
    pass

def method4(n):
    return n/(1/n)

n = 9
print(method1(n))
print(method2(n))
print(method4(n))