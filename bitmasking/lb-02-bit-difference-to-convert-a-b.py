# Function to find number of bits needed to be flipped to convert A to B
def countBitsFlip(self,a,b):
    ans =  a ^ b
    c=0
    while ans:
        if ans&1:
            c+=1
        ans = ans>>1
    ##Your code here
    return c