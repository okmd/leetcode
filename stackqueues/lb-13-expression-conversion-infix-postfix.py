# There are three types of expressions - infix, prefix, postfix.
# So, there will be 3!=6 possible interconversions.
# infix <-> postfix
# infix <-> prefix
# prefix <-> postfix

# Convertion 1: Infix -> Postfix
def infix_to_postfix(exp):
    op_stack = []
    postfix = []
    precedance = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    for e in exp:
        if e == '(':
            op_stack.append(e)
        elif e == ')':
            # pop while opening bracket
            while len(op_stack) and op_stack[-1] != '(':
                postfix.append(op_stack.pop())
            op_stack.pop()  # discarding opening (

        elif e in precedance:
            # ( can come in between so dict will return false[0].
            while len(op_stack) and precedance[e] <= precedance.get(op_stack[-1], 0):
                postfix.append(op_stack.pop())
            op_stack.append(e)

        else:
            postfix.append(e)
    # append remaing to postfix
    while len(op_stack):
        postfix.append(op_stack.pop())
    return "".join(postfix)

# Evaluation 1: postfix expression
def operate(a, b, e):
    if e == '+':
        r = a+b
    elif e == '-':
        r = a-b
    elif e == '*':
        r = a*b
    elif e == '/' and b != 0:
        r = a/b
    elif e == '^':
        r = a**b
    return r


def evaluate_postfix(exp):
    op_stack = []
    operator = "+-*/^"
    for e in exp:
        if e in operator:
            # take 2 operand and apply operation and insert back
            # NOTE: here oder of operarion is, top of stack is 2nd operand and next top is 1st operand. reverse in prefix.
            b = op_stack.pop()
            a = op_stack.pop()
            op_stack.append(operate(a, b, e))
        else:
            # it is operand
            op_stack.append(int(e))
    return op_stack[-1]

# NOTE: prefix evaluation is same as postfix instead right to left expression scan.


if __name__ == "__main__":
    exp = "1+2*(3^2-5)^(8-1*8)-9"
    postfix = infix_to_postfix(exp)
    print(postfix)
    print(evaluate_postfix(postfix))
