# Given the keypad of mobile phone
# Immediate neighbours can be pressed except * and #
# Given n length word

keypad = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9],
          ['*', 0, '#']]

# e.g if 1 length word = can start from 0 to 9 hence total 10 words.
# e.g if 2 length word = can start from 0 to 9 for 1st number,
# if 0 is pressed then 0 and 8 can be pressed,
# if 1 is pressed then 1, 2 and 4 can be pressed ...

keypadmap = {0: [0, 8], 1: [1, 2, 4], 2: [1, 2, 3, 5],
             3: [2, 3, 6], 4: [1, 4, 5, 7], 5: [2, 4, 5, 6, 8],
             6: [3, 5, 6, 9], 7: [4, 7, 8], 8: [0, 5, 7, 8, 9],
             9: [6, 8, 9]}


def mobile_keypad(n):
    # each row represent the digits length
    dp = [[0]*10 for i in range(n)]
    for i in range(n):
        # j represent the key pressed
        for j in range(10):
            # when only one time key is pressed i.e each key can be pressed one time
            if i == 0:
                dp[i][j] = 1
            # more than one time
            else:
                # start building the table from row = 1
                # i.e when 0 is pressed 2nd time then either 0/8 must be pressed first time.
                for k in keypadmap[j]:  # k 0 and 8 for when j=0 pressed
                    dp[i][j] += dp[i-1][k]

    return sum(dp[n-1])


print(mobile_keypad(16))
