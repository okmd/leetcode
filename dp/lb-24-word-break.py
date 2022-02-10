
def wb1_memoization(string, dictionary):
    dp = [-1]*len(string)
    def helper(string, dictionary, pos):
        if pos == len(string):
            return True
        
        if dp[pos]!=-1:
            return dp[pos]
        # generate all the substring from pos to n
        # if substring exits in dictionary then only find the remaining 
        # if it is possible to split all the string then return true else false
        for i in range(pos, len(string)+1):# i|like
            if string[pos:i+1] in dictionary and helper(string, dictionary, i+1):
                dp[pos] = True
                return dp[pos] 
            
        dp[pos] = False 
        return dp[pos]
    # start from 0 index
    return helper(string, dictionary, 0)

def wb1_tabulation(string, dictionary):
   pass
   # window technique
   # https://gist.github.com/SuryaPratapK/e6e3cc77abea23a51c2030d0ed33404d

# both for word break I.
# https://www.youtube.com/watch?v=2NaaM_z_Jig&ab_channel=Pepcoding
def wb1_tabulation_pepcoding(string, dictionary):
    n = len(string)
    dp = [0]*n # create a dp of size string.
    for i in range(n):
        # generate all suffixes of string 0 to i using j
        for j in range(i+1):
            # if string is in the dictionary then only increase the word count
            if string[j:i+1] in dictionary: # 0-i, 1-i,2-i, .. i - i+1
                if j>0:# append the current word to previous word
                    dp[i] += dp[j-1]
                else: # first element
                    dp[i] +=1  
    return dp[n-1]>0
    


# change it to tries, dictionary for faster lookup
dictionary = ["cat", "cats", "and", "sand", "dog"]
string = "catsanddog"

print(wb1_memoization(string, dictionary))
print(wb1_tabulation_pepcoding(string, dictionary))