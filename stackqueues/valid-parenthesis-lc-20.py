# Idea is to match the opening and closing brackets.
# bracket type and order should be maintinaed
brackets = {"(":")", "{":"}", "[":"]"}
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

    return len(stack)==0

            

print(is_valid("()"))
print(is_valid("()[]{}"))
print(is_valid("(]"))