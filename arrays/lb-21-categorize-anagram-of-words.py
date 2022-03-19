import unittest
# You are given list of words and you need to find all group with same anagram.
# a = [act, god, cat, dog, tac],
# out = [act, cat, tac], [god, dog]

def find_anagram_group(words):
    anagrams = dict()
    for word in words:
        sorted_word = "".join(sorted(word))
        if sorted_word in anagrams:
            anagrams[sorted_word].append(word)
        else:
            anagrams[sorted_word] = [word]
    return anagrams

class TestAnagram(unittest.TestCase):
    def setUp(self):
        pass
    def test_group(self):
        words = ['act', 'god', 'cat', 'dog', 'tac']
        actual_groups = [['act','cat','tac'], ['god', 'dog']]
        groups = find_anagram_group(words).values()
        for group,actual_group in zip(groups, actual_groups):
            self.assertEqual(group, actual_group)
            
    def test_group2(self):
        words = ['no', 'on', 'is']
        actual_groups = [['no', 'on'], ['is']]
        groups = find_anagram_group(words).values()
        for group,actual_group in zip(groups, actual_groups):
            self.assertEqual(group, actual_group)
            

if __name__=="__main__":
    unittest.main()
    
    

        