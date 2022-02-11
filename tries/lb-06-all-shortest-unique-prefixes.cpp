#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
 public:
  int freq;
  bool terminal;
  Node *chars[26];
  Node() {
    freq = 0;
    for (int i = 0; i < 26; i++) {
      chars[i] = NULL;
    }
    terminal = false;
  }
};
class Trie {
  Node *root;

 public:
  Trie() { root = new Node(); }
  int get_index(char c) { return c - 'a'; }
  void insert(string word) {
    int index;
    Node *temp = root;
    for (int i = 0; i < word.length(); i++) {
      char w = word[i];
      index = get_index(w);
      if (!temp->chars[index]) {
        temp->chars[index] = new Node();
      }
      temp = temp->chars[index];
      temp->freq += 1;
    }
    temp->terminal = true;
  }
  vector<string> unique_prefixes(string words[], int n) {
    vector<string> ans;
    int index;
    Node *temp;
    for (int i = 0; i < n; i++) {
      temp = this->root;
      for (int j = 0, k = 1; j < words[i].length(); j++, k++) {
        char w = words[i][j];
        index = get_index(w);
        if (temp->chars[index]) {
          if (temp->chars[index]->freq == 1) {
            ans.push_back(words[i].substr(0, k));
            break;
          }
          temp = temp->chars[index];
        }
      }
    }
    return ans;
  }
};

int main() {
  int n = 3;
  string words[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
  Trie t = Trie();
  for (int i = 0; i < n; i++) t.insert(words[i]);

  vector<string> ans = t.unique_prefixes(words, n);
  for (auto x : ans) {
    cout << x << " ";
  }
}