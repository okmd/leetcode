# Given stream of chars, you need to find the nonrepeating char
def non_preating_chars(string):
    non_repeating = [None]*26 # list of repeating char
    repeated = [False]*26 # 26 char 0 to 25, a->0, z->25
    
    for ch in string:
        elem_index = ord(ch) - ord('a')
        if repeated[elem_index]:
            # do nothing for this element, as 
            #  this already been repeated.
            continue
        elif non_repeating[elem_index]:
            non_repeating[elem_index] = None
            repeated[elem_index] = True
        else:
            non_repeating[elem_index] = ch
        
    # first non repeating char will be at 
    return list(filter(lambda x: x!=None, non_repeating))
            

if __name__=="__main__":
    st = "abcdaaabxyz"
    repeated = non_preating_chars(st)
    if len(repeated)==0:
        print("No, All repeated elements.")
    else:
        print("Yes, First non repeated: ", repeated[0])