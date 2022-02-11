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
    # find the prefix if exits of not
    # if it exists then call for all the words starting with this prefix
    # starting root is that root only
    def suggestions(self, word):
        root = self.root
        for w in word:
            index = self.get_idx(w)
            if not root.chars[index]:
                return [0]
            root = root.chars[index]
        # recursively create list of all words with given prefix
        return self.string_starting_here(root, word)
        
    def string_starting_here(self, root, prefix):
        ans = []
        def helper(root, prefix):
            # if not a node i.can be ommited
            if not root:
                return
            # take it ans only if it is a word i.e end here
            if root.terminal:
                # now prefix has complete word from path
                ans.append(prefix)
            # for each child in order call the function and return ans
            for i, node in enumerate(root.chars):
                # only if child has a node i.e char exits
                if node:
                    helper(node, f"{prefix}{chr(i+97)}")
                    
        helper(root, prefix)
        return ans
                
    def phone_dictionary(self, word):
        ans = []
        for i in range(len(word)):
            prefix = word[:i+1]
            ans.append(self.suggestions(prefix))
        return ans
    
    
t = Trie()
c = ["geeikistest", "geeksforgeeks", "geeksfortest"]
s = "geeips"
for i in c:
    t.insert(i)
print(t.phone_dictionary(s))