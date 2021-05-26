# checking the expression the have balnacend parenthesis
# Two cases: Either stack is not empty or stack top not match with elements.
# O(n) -> string size
def parenthesisCheck(expression):
    stack = []
    opening ="({["
    closing = ")}]"
    for e in expression:
        if e in opening:
            stack.append(opening.index(e))
        elif e in closing:
            if closing[stack.pop()]!=e:
                return False
            
    return len(stack)==0

if __name__=="__main__":
    operations = "[7-(s+{a+b)-b}+8]"
    print(f"{'Balanced' if parenthesisCheck(operations) else 'Not balanced'}.")
                
            
        