import unittest

# iterarive appraoch
def apowerb(a,b):
    res = 1
    while b:
        if b&1:
            res *= a
        a *= a
        b = b//2
    return res

# recursive approach
def apowerb2(a,b):
    if b==0:
        return 1
    if b==1:
        return a
    if b&1:
        res = apowerb2(a, b-1) * a
    else:
        temp = apowerb2(a, b//2)
        res = temp*temp
    return res

class Test(unittest.TestCase):
    def test_1(self):
        self.assertEqual(apowerb(4,3), 4**3)
        self.assertEqual(apowerb(3,3), 3**3)
        self.assertEqual(apowerb(14,3), 14**3)
        self.assertEqual(apowerb(1400,3000), 1400**3000)
        print("Method 2")
        self.assertEqual(apowerb2(14,3), 14**3)
        self.assertEqual(apowerb2(1400,3000), 1400**3000)



if __name__=="__main__":
    unittest.main()