class TrieNode:
    def __init__(self):
        self.chars = [[0,0]]*26 # Node and count of words starting with this node
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
            if not root.chars[index][0]:
                root.chars[index] = [TrieNode(), 0]
            # already present then increase count and move ahead
            root.chars[index][1]+=1
            root = root.chars[index][0]
        root.terminal = True
    
    def unique_prefixes(self, words):
        ans = []
        def helper(root, word):
            for i, w in enumerate(word):
                index = self.get_idx(w)
                if root.chars[index][0]:
                    # only one word from this node then it must be the prefix
                    if root.chars[index][1]==1:
                        ans.append(word[:i+1])
                        break
                    root = root.chars[index][0]
                # else not present in the tree

          
        for w in words:          
            helper(self.root, w)
            
        return ans
                
    
t = Trie()
# c = ["zebra", "dog", "duck", "dove"]
c = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
for i in c:
    t.insert(i)
print(t.unique_prefixes(c))

# Note Trie can also be modified to store the count of each word staring with char
# to reduce the constant searching time each time for each node = O(nk)

# Giving Memory Error on Large input?