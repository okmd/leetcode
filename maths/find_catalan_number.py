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

class Test(unittest.TestCase):
    def test_1(self):
        self.assertEqual(Cn(6), 132)
        print(dp)
        self.assertEqual(Cn(5), 42)
        self.assertEqual(Cn(4), 14)
        self.assertEqual(Cn(3), 5)
        self.assertEqual(Cn(2), 2)
        print(dp)
        self.assertEqual(Cn(1), 1)

if __name__=="__main__":
    unittest.main()
