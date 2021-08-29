# NOTE: Infix expression requires precedance and associativity.
# NOTE: Postfix and Prefix expression do not require anything like associativity or precedance.
# NOTE: Compiler convert infix to anyone of postfix or prefix expression before using it.
# NOTE: do not use this method instead use pre/postfix.

def operation(a, b, e):
    if e == '-':
        return a - b
    elif e == '+':
        return a + b
    elif e == '*':
        return a*b
    elif e == "/" and b != 0:
        return a/b

# USE 1: if only same precedance operator is present in expression.


def same_pre_exp(expression):
    # assuming expression is valid

    result = None
    for i in range(1, len(expression)-1, 2):
        if result == None:
            result = expression[i-1]
        if expression[i] in '+-':
            result = operation(int(result),  int(
                expression[i+1]), expression[i])

    return result

# USE 2: with different precedance and associativity


def diff_pre_exp(exp):
    # expression contains *,/ and +, - -> LR -> TB
    operator_stack = []
    operand_stack = []
    high = "*/"
    low = "+-"
    i = 0
    while i < len(exp):
        if exp[i] in high:
            a = operand_stack.pop()
            operand_stack.append(operation(a, int(exp[i+1]), exp[i]))
            i+=1
        elif exp[i] in low:
            operator_stack.append(exp[i])
        else:
            operand_stack.append(int(exp[i]))
        i+=1
    # reverse both the stack as they are left associative otherwise it will calcualte as right associative way.
    # i.e the op which came first must be evaluated first.
    # as this is stack, will pop from top
    operator_stack = operator_stack[::-1]
    operand_stack = operand_stack[::-1]
    res = operand_stack.pop()
    while len(operator_stack):
        res = operation(operand_stack.pop(), res, operator_stack.pop())
    return res


if __name__ == "__main__":
    expression = "3+2-1-5-3-3+9+9"
    print(f"{expression}={same_pre_exp(expression)}")
    expression = "3+2*5/1-2*5/5"
    print(f"{expression}={diff_pre_exp(expression)}")
