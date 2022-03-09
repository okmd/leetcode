# Idea is to match the opening and closing brackets.
# bracket type and order should be maintinaed
brackets = {"(": ")", "{": "}", "[": "]"}


def is_valid(s):
    stack = []
    for i in s:
        if i in brackets:
            stack.append(brackets[i])
        elif len(stack):
            top = stack.pop()
            if i != top:
                return False
        else:
            return False

    return len(stack) == 0


def max_valid_substring(s):
    n = len(s)
    stack = [-1]
    ans = 0
    for i in range(n):
        # start of the 
        if s[i] == '(':
            stack.append(i)
        else:
            if len(stack):
                stack.pop()
            # still not empty
            if len(stack):
                ans = max(ans, i - stack[-1])
            else:
                stack.append(i)
    return ans


print(is_valid("()"))
print(is_valid("()[]{}"))
print(is_valid("(]"))
print(max_valid_substring("))()(()"))  # 2
