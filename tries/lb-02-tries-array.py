class TrieNode:
    def __init__(self):
        self.chars = [0]*26
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
        root.terminal = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        root = self.root
        for w in word:
            index = self.get_idx(w)
            if not root.chars[index]:
                return False
            root = root.chars[index]

        return root.terminal

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        root = self.root
        for w in prefix:
            index = self.get_idx(w)
            if not root.chars[index]:
                return False
            root = root.chars[index]

        return True
    
    def word_break(self, s):
        def __helper(s):
            if len(s)==0:
                return True
            for i in range(1, len(s)+1):
                if self.search(s[:i]) and __helper(s[i:]):
                    return True
            return False

        return __helper(s)





s = "aaaaaaa"
d = ["apple","pen"]
# d = ['aaaa', 'aaa']
t = Trie()
for w in d:
    t.insert(w)

print(t.word_break(s))