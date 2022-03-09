# Recursivly call insert and at the end insert

def insert(st, val):
    if len(st) == 0:
        st.append(val)
        return
    top = st.pop()
    insert(st, val)
    st.append(top)


st = [1, 3, 5]
insert(st, 7)
print(st)
