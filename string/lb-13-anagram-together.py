def create_sorted_word(mp):
    ls = []
    for i, v in enumerate(mp):
        for j in range(v):
            ls.append(chr(i+97))
    return "".join(ls)


def Anagrams(self, words, n):
    '''
    words: list of word
    n:      no of words
    return : list of group of anagram {list will be sorted in driver code (not word in grp)}
    '''
    # Instead of sorting each element
    # just max 26 char if same elements are present then it is anagram O(nk)
    anagrams = dict()

    for word in words:
        mp = [0]*26
        for w in word:
            mp[ord(w) - ord('a')] += 1
        # make sorted word
        sorted_word = create_sorted_word(mp)
        if not anagrams.get(sorted_word, None):
            anagrams[sorted_word] = [word]
        else:
            anagrams[sorted_word].append(word)

    return anagrams.values()
