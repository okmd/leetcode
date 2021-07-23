import unittest
# You are given string s and you need to place char<count>
# out is reverse of above string.
# s = "aabc"
# step1: a2b1c1
# output : 1c1b2a
# https://practice.geeksforgeeks.org/problems/encrypt-the-string-10337/1#


def find_ecrypted_string(string):
    output = []
    count, i = 1, 0
    while i < len(string):
        output.append(string[i])
        while i < len(string)-1 and string[i] == string[i+1]:
            count += 1
            i += 1
        # make sure number also get reversed as 15 become 51
        output += [i for i in str(count)]
        i += 1
        count = 1
    return "".join(reversed(output))


class TestString(unittest.TestCase):
    def test_empty(self):
        self.assertEqual(find_ecrypted_string(""), "")

    def test_str1(self):
        self.assertEqual(find_ecrypted_string("aabc"), "1c1b2a")

    def test_str2(self):
        self.assertEqual(find_ecrypted_string("aaaaa"), "5a")

    def test_str3(self):
        self.assertEqual(find_ecrypted_string("yutg"), "1g1t1u1y")

    def test_str4(self):
        self.assertEqual(find_ecrypted_string("aabaac"), "1c2a1b2a")
        
    def test_str5(self):
        self.assertEqual(find_ecrypted_string("dskfjdsfjsfklhjgfrehitaaaaaaaakjhkdhsjhfehfeeuuuuuuuuuuuuoetiroitoritttttttttttttttdfnbsfdhs"), "1s1h1d1f1s1b1n1f1d51t1i1r1o1t1i1o1r1i1t1e1o21u2e1f1h1e1f1h1j1s1h1d1k1h1j1k8a1t1i1h1e1r1f1g1j1h1l1k1f1s1j1f1s1d1j1f1k1s1d")


if __name__ == "__main__":
    unittest.main()
