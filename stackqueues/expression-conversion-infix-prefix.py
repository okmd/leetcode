
# Convertion 1: Infix -> Prefix
def infix_to_prefix(exp):
    # MODIFICATION in postfix
    exp = exp[::-1]# reverse
    # repalce (<->)
    exp = exp.replace('(', 'o').replace(')', '(').replace('o', ')')
    # END
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
            # MODI
            if e == '^':
                while len(op_stack) and precedance[e] <= precedance.get(op_stack[-1], 0):
                    postfix.append(op_stack.pop())
            else:
                while len(op_stack) and precedance[e] < precedance.get(op_stack[-1], 0):
                    postfix.append(op_stack.pop())
            #END

            op_stack.append(e)

        else:
            postfix.append(e)
    # append remaing to prefix
    while len(op_stack):
        postfix.append(op_stack.pop())
    # reverse to get prefix
    return "".join(postfix)[::-1]

# Evaluation 1: prefix expression
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


def evaluate_prefix(exp):
    op_stack = []
    operator = "+-*/^"
    # moving in opposite direction and alog is same as postfix evaluation
    for e in exp[::-1]:
        if e in operator:
            # take 2 operand and apply operation and insert back
            # NOTE: here oder of operarion gets swapped, top of stack is 1st operand, next top is second operand.
            a = op_stack.pop()
            b = op_stack.pop()
            op_stack.append(operate(a, b, e))
        else:
            # it is operand
            op_stack.append(int(e))
    return op_stack[-1]

# NOTE: prefix evaluation is same as prefix instead right to left expression scan.


if __name__ == "__main__":
    exp = "1+2*(3^2-5)^(8-1*8)-9"
    prefix = infix_to_prefix(exp)
    print(prefix)
    print(evaluate_prefix(prefix))
