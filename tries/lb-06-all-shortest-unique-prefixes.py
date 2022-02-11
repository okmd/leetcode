class TrieNode:
    def __init__(self):
        self.freq = 0 # denotes the word count starting from here
        self.chars = [0]*26 # Node and count of words starting with this node
        self.terminal = False


class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def get_idx(self, w):
        return ord(w) - ord('a')

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        root = self.root
        for w in word:
            index = self.get_idx(w)
            if not root.chars[index]:
                root.chars[index] = TrieNode()
            root = root.chars[index]
            root.freq += 1
        root.terminal = True
    
    def unique_prefixes(self, words):
        ans = []
        def helper(root, word):
            for i, w in enumerate(word):
                index = self.get_idx(w)
                if root.chars[index]:
                    if root.chars[index].freq==1:
                        # prefix answer
                        ans.append(word[:i+1])
                        break
                    root = root.chars[index]

        for word in words:      
            helper(self.root, word) 
        return ans
                
    
t = Trie()
words = ["zebra", "dog", "duck", "dove"]
words = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]

for word in words:
    t.insert(word)

print(t.unique_prefixes(words))
# print(ans)

# Note Trie can also be modified to store the count of each word staring with char
# to reduce the constant searching time each time for each node = O(nk)

# Giving Memory Error on Large input?
# Giving TLE even after using frequency per node instead of char.