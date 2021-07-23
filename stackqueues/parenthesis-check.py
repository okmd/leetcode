import unittest
# checking the expression the have balnacend parenthesis
# Two cases: Either stack is not empty or stack top not match with elements.
# O(n) -> string size


def parenthesisCheck(expression):
    stack = []
    opening = "({["
    closing = ")}]"
    for e in expression:
        if e in opening:
            stack.append(opening.index(e))
        elif e in closing:
            # there is nothing in the stack but you are getting to remove element from the stack.
            # or no opening bracket but there is a closing bracket.
            if len(stack)==0:
                return False
            if closing[stack.pop()] != e:
                return False

    return len(stack) == 0


class TestCode(unittest.TestCase):
    def test_code(self):
        operations = "[7-(s+{a+b)-b}+8]"
        self.assertEqual(parenthesisCheck(operations), False)

    def test_code2(self):
        operations = "[()]{}{[()()]()}"
        self.assertEqual(parenthesisCheck(operations), True)

    def test_code3(self):
        operations = "[(])"
        self.assertEqual(parenthesisCheck(operations), False)
        
    def test_code_edge1(self):
        operations = "["
        self.assertEqual(parenthesisCheck(operations), False)
        
    def test_code_edge2(self):
        operations = ")"
        self.assertEqual(parenthesisCheck(operations), False)
    
    def test_code_edge3(self):
        operations = ""
        self.assertEqual(parenthesisCheck(operations), True)
        
    def test_code4(self):
        operations = "[[]}"
        self.assertEqual(parenthesisCheck(operations), False)


if __name__ == "__main__":
    unittest.main()
    # operations = "[7-(s+{a+b)-b}+8]"
    # print(f"{'Balanced' if parenthesisCheck(operations) else 'Not balanced'}.")
