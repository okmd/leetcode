from collections import defaultdict
import unittest


class Node:
    def __init__(self):
        self.terminal = None
        self.characters = defaultdict(bool)


class Tries:
    def __init__(self):
        self.root = Node()

    def add_word(self, word):
        temp = self.root
        for w in word:
            if not temp.characters[w]:
                temp.characters[w] = Node()
            temp = temp.characters[w]

        temp.terminal = True

    def search(self, word):
        temp = self.root
        for w in word:
            if not temp.characters[w]:
                return False
            temp = temp.characters[w]
        return temp.terminal

    def _get_item_helper(self, node, word, level, results):
        if node.terminal:
            results.append("".join(word[:level]))

        for w in node.characters.keys():
            word.insert(level, w)
            self._get_item_helper(node.characters[w], word, level+1, results)

    def get_items(self):
        results = []
        self._get_item_helper(self.root, [], 0, results)
        return results


class TestTries(unittest.TestCase):
    def setUp(self):
        self.words = ["Programming", "Program", "Hi", "Hello", "Coding"]
        self.t = Tries()
        for word in self.words:
            self.t.add_word(word)

    def test_yes(self):
        test_string = self.words[3]
        self.assertEqual(self.t.search(test_string), True)

    def test_two(self):
        test_string = "my"
        self.assertEqual(self.t.search(test_string), False)

    def test_print(self):
        for i in self.t.get_items():
            self.assertIn(i, self.words)


if __name__ == "__main__":
    unittest.main()
