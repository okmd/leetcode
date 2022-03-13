def red(string):
    # assuming balanced
    st = []
    for s in string:
        if s == ')':
            redundancy = True
            while(len(st) and st[-1] != '('):
                ele = st.pop()
                if ele in '+-*/':
                    redundancy = False
            # pop opening
            st.pop()
            if redundancy:
                return True
        else:
            st.append(s)
    # no redundancy found
    return False


print(red("((a+b))"))
print(red("(a+(b)/c)"))
print(red("(a+b*(c-d))"))
print(red("()"))
print(red("(a+b*(c-(d)))"))
