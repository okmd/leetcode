def basic(words):
    # O(n*s*logs)
    anagrams = dict()
    for word in words:
        sorted_word = "".join(sorted(word))
        if sorted_word in anagrams:
            anagrams[sorted_word].append(word)
        else:
            anagrams[sorted_word] = [word]
    return anagrams.values()

# https://www.youtube.com/watch?v=0I6IL3TnIZs&ab_channel=TECHDOSE

def create_sorted_word(mp):
    ls = []
    for i,v in enumerate(mp):
        for j in range(v):
            ls.append(chr(i+97))
    return "".join(ls)

def using_tries_concept(words):
    # Instead of sorting each element
    # just max 26 char if same elements are present then it is anagram O(nk)
    anagrams = dict()
    
    for word in words:
        mp = [0]*26
        for w in word:
            mp[ord(w) - ord('a')]+=1
        # make sorted word
        sorted_word = create_sorted_word(mp)
        if not anagrams.get(sorted_word, None):
            anagrams[sorted_word] = [word]
        else:
            anagrams[sorted_word].append(word)
            
    return anagrams.values()
                    
            
        
print(using_tries_concept(["eat", "tea", "tan"]))
print(using_tries_concept(["ab", "abb", "tan"]))
    
    
    