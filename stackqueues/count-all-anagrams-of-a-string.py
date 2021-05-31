# given an sequence and a string of size.
# need to find the anagram of string present in the sequence and count it.
# This problem is similar to finding all substing of size k, sliding window.

# NOTE: Anagaram has n! valid string i,e ab -> ab, ba
# All anagram have equal no of chars and same chars.
# HELP: Aditya Verma YTB
def count_anagram(seq, str_seq):
    k = len(str_seq)
    # create
    to_be_found = {}
    for key in str_seq:
        to_be_found[key] = to_be_found.get(key, 0) + 1
    print(to_be_found)
    i, j, ans = 0, 0, 0
    # distinct chars, to be found
    count = len(to_be_found.keys())
    while j < len(seq):
        # if present, decrease its count
        if to_be_found.get(seq[j],None)!=None:  # presnet
            to_be_found[seq[j]] -= 1
            # if anyone of chrs count become 0 i.e fully found this char.
            if to_be_found[seq[j]] == 0:
                # now 1 less no of chars need to found.
                # count is used to avoid the map traversal
                count -= 1
        if j-i+1 < k:
            j += 1
        elif j-i+1 == k:
            # if count is 0 i.e all the required chrs are found
            if count == 0:
                ans += 1
                print(seq[i:j+1])
                # to remove left value if present in map, as no longer part of map.
            if to_be_found.get(seq[i], None) != None:  # presnet
                # altest one of them not found completely.
                if to_be_found[seq[i]] == 0:
                    count += 1
                # now required increases
                to_be_found[seq[i]] += 1
            # slide the window
            i += 1
            j += 1
    return ans


if __name__ == "__main__":
    sequence = ["aabaabaa", "baaabaaab","forxxorfxdofr"]
    str_sq = ["aaba", "aaa","for"]
    for i, j in zip(sequence, str_sq):
        print(f"There are {count_anagram(i, j)} anagram of string '{j}' in sequence '{i}'.")
