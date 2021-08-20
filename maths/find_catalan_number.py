import unittest
# dp soluton to find catalan number
# nth catalan number is Cn = {(4n - 2 )/(n+1)} Cn-1
# 1st catalan number is 1
# catalan series 1,1,2,5,14,42,134 ...
dp = [0]*10  # dont consiter 0


def Cn(n):
    if n == 1:
        dp[n] = 1
        return dp[n]
    if dp[n]:
        return dp[n]

    dp[n] = ((4*n-2) / (n+1))*Cn(n-1)
    return dp[n]


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def Cn_fact(n):
    # 2nCn / (n+1)
    # 2n! / (n+1)! (n)!
    # (2n)! / (n+1) n! n!
    # {(2n)*(2n-1)*(2n-2)* .. *(2n-(n-1))*(2n-n)!}\ {n*(n-1)*(n-2)* .. *1}
    temp = n
    num = 1
    den = 1
    r = n
    n = 2*n
    if r!=1:
        while r:
            num *= n
            den *= r
            g = gcd(num, den)
            num //= g
            den //= g
            n = n-1
            r = r-1
    else:
        num = n
    num = num//(temp+1)
    return num


class Test(unittest.TestCase):
    def test_1(self):
        self.assertEqual(Cn(6), 132)
        self.assertEqual(Cn_fact(6), 132)
        print(dp)
        self.assertEqual(Cn(5), 42)
        self.assertEqual(Cn(4), 14)
        self.assertEqual(Cn_fact(4), 14)
        self.assertEqual(Cn(3), 5)
        self.assertEqual(Cn(2), 2)
        print(dp)
        self.assertEqual(Cn(1), 1)
        self.assertEqual(Cn_fact(1), 1)


if __name__ == "__main__":
    unittest.main()
