import math
# Find position of set bit 
def p2(self, n):
        return (n>0 and (n&(n-1))==0)
        
def findPosition(self, N):
    if N==1:
        return 1
    if self.p2(N):
        return int(math.log(N, 2) + 1)
    return -1